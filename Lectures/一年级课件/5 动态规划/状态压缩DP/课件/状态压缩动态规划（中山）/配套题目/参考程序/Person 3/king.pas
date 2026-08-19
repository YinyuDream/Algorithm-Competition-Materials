var
  n,m:longint;
  f:array[0..9,0..512,0..81] of int64;
  i,j,k,l,o:longint;
  ans:int64;

function can(a:longint):boolean;
var
  i,k:longint;
begin
  k:=3;
  for i:=1 to n-1 do
    begin
      if k and a=k then
        exit(false);
      k:=k shl 1;
    end;
  exit(true);
end;

function count(a:longint):longint;
var
  i,s:longint;
begin
  s:=0;
  for i:=1 to n do
    if a shr (i-1) mod 2=1 then
      inc(s);
  exit(s);
end;

begin
  assign(input,'king.in');
  reset(input);
  assign(output,'king.out');
  rewrite(output);
  readln(n,m);
  f[0,0,0]:=1;
  for i:=1 to n do
    for j:=0 to 1 shl n-1 do
      if can(j) then
        for k:=0 to 1 shl n-1 do
          if (j and k=0) and can(j or k) then
            begin
              l:=count(j);
              for o:=l to m do
                inc(f[i,j,o],f[i-1,k,o-l]);
            end;
  for j:=0 to 1 shl n-1 do
    inc(ans,f[n,j,m]);
  writeln(ans);
  close(input);
  close(output);
end.