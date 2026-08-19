const c:array[1..9]of longint=(1,2,4,8,16,32,64,128,256);
var n,m,i,j,k,l,s:longint;ans:int64;
    a:array[0..512]of longint;
    b:array[0..512]of boolean;
    g:array[1..90]of longint;
    f:array[0..9,0..512,0..90]of int64;
begin
  assign(input,'king.in');reset(input);
  assign(output,'king.out');rewrite(output);
  fillchar(f,sizeof(f),0);
  readln(n,m);
  a[1]:=1;
  for i:=2 to n do
  for j:=0 to c[i]-1 do
  a[c[i]+j]:=a[j]+1;
  b[0]:=true;b[1]:=true;
  for i:=2 to n do
  for j:=0 to c[i-1]-1 do
  b[c[i]+j]:=b[j];
  for i:=0 to c[n]+j do
  if b[i] then
  begin
    inc(s);
    g[s]:=i;
  end;
  for i:=1 to s do
  f[1,g[i],a[g[i]]]:=1;
  for i:=2 to n do
  for j:=1 to s do
  for k:=1 to s do
  if (g[j] and g[k]=0)and(b[g[j] or g[k]]) then
  for l:=a[g[k]] to m do
  f[i,g[j],a[g[j]]+l]:=f[i,g[j],a[g[j]]+l]+f[i-1,g[k],l];
  ans:=0;
  for i:=1 to s do
  ans:=ans+f[n,g[i],m];
  writeln(ans);
  close(input);close(output);
end.
