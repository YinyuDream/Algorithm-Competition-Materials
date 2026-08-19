memset(f,0x3f,sizeof(f));
for (int i=1;i<=n;i++)
	f[i][i]=0;

for (int len=2;len<=n;len++)
	for (int l=1,r=len;r<=n;l++,r++)
		for (int k=l;k<r;k++)
			f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+sum[l~r]);
