f[0][0]=0;
for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++)
	{
		f[i][j] = f[i-1][j];
		if (j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]);
	}

for (int i=0;i<n;i++)
	for (int j=0;j<=m;j++)
	{
		f[i+1][j] = max(f[i+1][j],f[i][j]);
		f[i+1][j+v[i+1]] = max(f[i+1][j+v[i+1]], f[i][j]+w[i]);
	}

for (int i=1;i<=n;i++)
	for (int j=m;j>=v[i];j--)
		f[j] = max(f[j],f[j-v[i]] + w[i]);


