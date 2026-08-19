void prim(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	for (int i=1;i<=n;i++)
	{
		int p=-1;
		for (int j=1;j<=n;j++)
			if (!right[j] && (p==-1 || dist[p] > dist[j])) p=j;
		right[p]=true;
		for (int j=first[p];j!=0;j=ed[j].next)
			dist[ed[j].e] = min(dist[ed[j].e], ed[j].d);
	}
}

