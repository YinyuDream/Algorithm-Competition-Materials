for (int i=1;i<=m;i++)
	cin >> s[i] >> e[i] >> d[i];

memset(dist,0x3f,sizeof(dist));
dist[1]=0;
for (int i=1;i<n;i++)
	for (int j=1;j<=m;j++)
		dist[e[j]] = min(dist[e[j]], dist[s[j]] + d[j]);
