type
  arr=array[0..100] of longint;
var
  n,m:longint;
  t:longint;
  f:array[0..40,0..4096,0..100] of longint;
  i,j,k:longint;
  a:array[1..20] of longint;

function max(a,b:longint):longint;
begin
  if a>b then
    exit(a)
  else
    exit(b);
end;

function canj(a:longint):boolean;
var
  i,s:longint;
begin
  s:=0;
  i:=0;
  while a<>0 do
    begin
      inc(i);
      if a mod 2=1 then
        if s=0 then
          s:=i
        else if s=i-1 then
          s:=0
        else
          exit(false);
      a:=a shr 1;
    end;
  if s=0 then
    exit(true)
  else
    exit(false);
end;

procedure jia(var a,b:arr);
var
  i:longint;
begin
  a[0]:=max(a[0],b[0]);
  for i:=1 to a[0] do
    a[i]:=a[i]+b[i];
  inc(a[0]);
  for i:=1 to a[0] do
    begin
      a[i+1]:=a[i+1]+a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
  while (a[a[0]]=0) and (a[0]>0) do
    dec(a[0]);
end;

begin
  assign(input,'floor.in');
  reset(input);
  assign(output,'floor.out');
  rewrite(output);
  readln(n,m);
  if n<m then
    begin
      t:=n;n:=m;m:=t;
    end;
  t:=(1 shl m)-1;
  for i:=0 to t do
    if canj(i) then
      begin
        f[1,i,0]:=1;
        f[1,i,1]:=1;
      end;
  for i:=1 to m-1 do
    a[i]:=(1 shl (i-1))+(1 shl i);
  for i:=2 to n do
    begin
      for j:=0 to t do
        f[i,t xor j]:=f[i-1,j];
      for k:=1 to m-1 do
        for j:=0 to t do
          if j and a[k]=0 then
            jia(f[i,j+a[k]],f[i,j])
    end;
  for i:=f[n,t,0] downto 1 do
    write(f[n,t,i]);
  writeln;
  close(input);
  close(output);
end.
