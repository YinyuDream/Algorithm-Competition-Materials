void dfs(int now)
{
	for (int i=first[now];i!=0;i=ed[i].next)
		if (ed[i].e != f[now][0])
		{
			int p=ed[i].e;
			depth[p]=depth[now]+1;
			f[p][0]=now;
			g[p][0]=ed[i].d;
			for (int x=1;x<=18;x++)
			{
				f[p][x] = f[f[p][x-1]][x-1];
				g[p][x] = min(g[p][x-1],g[f[p][x-1]][x-1]);
			}
			dfs(p);
		}
}
O(nlogn)
dfs(1);

int get_lca(int p1,int p2)
{
	if (depth[p1] < depth[p2]) swap(p1,p2);
	int ans = INF;
	for (int x=18;x>=0;x--)
	{
		int p=f[p1][x];
		if (depth[p] >= depth[p2]) 
		{
			ans = min(ans,g[p1][x]);
			p1=p;
		}
	}
	if (p1==p2) return ans;
	for (int x=18;x>=0;x--)
		if (f[p1][x]!=f[p2][x]) 
		{
			ans=min(ans,min(g[p1][x],g[p2][x]));
			p1=f[p1][x];
			p2=f[p2][x];
		}
	return min(ans,min(g[p1][0],g[p2][0]));
}O(logn)












