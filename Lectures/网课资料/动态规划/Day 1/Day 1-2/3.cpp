f[0][0]=0;
for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++)
		for (int k=0;k*v[i] <= j;k++)
			f[i][j] = max(f[i][j], f[i-1][j-k*v[i]] + k*w[i]);

for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++)
	{
		f[i][j] = f[i-1][j];
		if (j>=v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
	}

for (int i=1;i<=n;i++)
	for (int j=v[i];j<=m;j++)
		f[j] = max(f[j],f[j-v[i]] + w[i]);



