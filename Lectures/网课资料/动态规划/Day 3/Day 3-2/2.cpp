int dfs(int s)
{
	if (s==0 || s==1) return 0;
	if (g[s]) return sg[s];
	g[s]=true;
	for (int i=2;i<=6 && i<=s;i++)
		dfs(s-i);
	cnt=0;
	for (int i=2;i<=6 && i<=s;i++)
		z[cnt++] = dfs(s-i);
	sort(z,z+cnt);
	cnt = unique(z,z+cnt)-z;
	z[cnt]=-1;
	for (sg[s]=0;sg[s] == z[sg[s]];sg[s]++);

	return sg[s];
}
int ans=0;
for (int i=1;i<=n;i++)
	ans = ans ^ dfs(a[i]);
if (ans) Alice wins;
else Bob wins;
