type arr=array[0..100]of longint;
var n,m,i,j,k,s:longint;
    f:array[1..40,0..4100,0..100]of longint;
    a:array[1..11]of longint;
function can(o:longint):boolean;
var i,p:longint;
begin
  can:=false;
  p:=3;
  for i:=1 to m do
  begin
    if o=0 then exit(true);
    if o and p=p then dec(o,p);
    p:=p shl 1;
  end;
end;
procedure jia(var a,b:arr);
var i:longint;
begin
  if b[0]>a[0] then a[0]:=b[0];
  for i:=1 to a[0] do
  begin
    a[i]:=a[i]+b[i];
    inc(a[i+1],a[i] div 10);
    a[i]:=a[i] mod 10;
  end;
  inc(a[0]);
  while (a[a[0]]=0)and(a[0]>0) do dec(a[0]);
end;
begin
  assign(input,'floor.in');reset(input);
  assign(output,'floor.out');rewrite(output);
  readln(n,m);
  if n<m then
  begin  s:=n;n:=m;m:=s;end;
  s:=1 shl m -1;
  for i:=0 to s do
  if can(i) then
  begin f[1,i,0]:=1;f[1,i,1]:=1;end;
  for i:=1 to m-1 do
  a[i]:=1 shl(i-1)+1 shl i;
  for i:=2 to n do
  begin
    for j:=0 to s do
    f[i,s xor j]:=f[i-1,j];
    for k:=1 to m-1 do
    for j:=0 to s do
    if j and a[k]=0 then
    jia(f[i,j+a[k]],f[i,j]);
  end;
  for i:=f[n,s,0] downto 1 do
  write(f[n,s,i]);
  close(input);close(output);
end.