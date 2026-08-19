n,m
v[i] w[i]

memset(f,-1,sizeof(f));
for (int i=0;i<n;i++)
	f[1<<i][i][v[i]] = 0;
for (int i=0;i<(1<<n);i++)
	for (int j=0;j<n;j++)
		if ((i>>j)&1)
			for (int k=0;k<=m;k++)
				if (f[i][j][k]!=-1)
					for (int r=0;r<n;r++)
						if (((i>>r)&1)==0)
							f[i|(1<<r)][r][k+v[r]] = max(f[i|(1<<r)][r][k+v[r]],f[i][j][k]+(w[j]^w[r]));
