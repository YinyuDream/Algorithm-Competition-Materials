void dfs(int now)
{
	t++;
	dfn[now]=low[now]=t;
	s[++size]=now;
	instack[now]=true;
	for (int i=first[now];i!=0;i=ed[i].next)
	{
		int e=ed[i].e;
		if (!dfn[e])
		{
			dfs(e);
			low[now] = min(low[now],low[e]);
		}
		else
		{
			if (instack[e]) low[now]=min(low[now],dfn[e]);
		}
	}
	if (dfn[now] == low[now])
	{
		cnt ++;
		belong[now]=cnt;
		while (s[size]!=now)
		{
			belong[s[size]] = cnt;
			instack[s[size]] = false;
			size--;
		}
		size--;
		instack[now]=false;
	}
}

for (int i=1;i<=n;i++)
	if (!dfn[i]) dfs(i);

for (int i=1;i<=n;i++)
	for (int j=first[i];j!=0;j=ed[j].next)
		if (belong[i] != belong[ed[j].e])
			add_edge2(belong[i],belong[ed[j].e],ed[j].d);

for (int i=1;i<=n;i++)
	value[belong[i]] += v[i];



