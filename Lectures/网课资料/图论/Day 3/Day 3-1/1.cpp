dfn[2333],low[2333]
void dfs(int now,int from)
{
	t++;
	dfn[now]=low[now]=t;
	vis[now]=true;
	for (int i=first[now];i;i=ed[i].next)
		if ((i^1)!=from)
		{
			int e=ed[i].e;
			if (!dfn[e])
			{
				dfs(e,i);
				low[now]=min(low[now],low[e]);
			}
			else
			{
				if (vis[e]) low[now]=min(low[now],dfn[e]);
			}
		}
	vis[e]=false;
}

for (int i=1;i<=n;i++)
	for (int j=first[i];j;j=ed[j].next)
	{
		int e=ed[j].e;
		if (low[e] > dfn[i] || low[i] > dfn[e]) ed[j].bridge=true;
	}


