bool dfs_circle(int now)
{
	vis[now]=true;
	for (int p=first[now];p!=0;p=ed[p].next)
		if (vis[ed[p].e])
		{
			if (ed[p].e==f[now]) continue;
			int x=now;
			while (x!=ed[p].e)
			{
				cnt++;
				cirle[cnt] = x;
				in_circle[x] = true;
				x=f[x];
			}
			cnt++;
			cirle[cnt] = x;
			in_circle[x] = true;
			x=f[x];
			return true;
		}
		else
		{
			f[ed[p].e] = now;
			if (dfs_circle(ed[p].e)) return true;
		}
	return false;
}

void dfs_dp(int now)
{
	for (int p=first[now];p!=0;p=ed[p].next)
		if (!in_circle[ed[p].e])
		{
		}
}
for (int i=1;i<=cnt;i++)
	dfs_dp(circle[i]);



