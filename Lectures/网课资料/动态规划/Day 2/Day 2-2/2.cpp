f[1][0]=1;

for (int i=1;i<n;i++)
	for (int j=0;j<=1;j++)
		for (int k=0;k<=i;k++)
			f[i+1][(j+i-k)%2] += f[i][j];
