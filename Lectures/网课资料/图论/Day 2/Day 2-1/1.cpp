l[i],r[i]

void dfs(int now,int f)
{
	q[l[now]] = now;
	int x=l[now]+1;
	size[now]=1;
	for (int i=first[now];i!=0;i=ed[i].next)
		if (ed[i].e != f)
		{
			l[ed[i].e] = x;
			dfs(ed[i].e,now);
			x = r[ed[i].e]+1;
			size[now] += size[ed[i].e];
		}
	r[now] = l[now] + size[now]-1;
}

l[1]=1;r[1]=n;
