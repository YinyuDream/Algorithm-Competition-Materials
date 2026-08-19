void dfs(int now,int fa)
{
	f[now] = 1;
	for (int p=first[now];p!=0;p=ed[p].next)
		if (ed[p].next != fa)
		{
			dfs(ed[p].e,now);
			f[now] += f[ed[p].e];
		}
}
