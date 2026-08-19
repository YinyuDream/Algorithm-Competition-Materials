void spfa(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while (q.size())
	{
		int now=q.front();
		q.pop();
		inque[now]=false;
		for (int i=first[now];i!=0;i=ed[i].next)
		{
			int e=ed[i].e;
			int d=dist[now] + ed[i].d;
			if (dist[e] > d)
			{
				dist[e]=d;
				if (!inque[e]) inque[e]=true,q.push(e);
			}
		}
	}
}
