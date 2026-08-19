int solve(int x)
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	int k=0;
	while (x!=0)
	{
		y[++k] = x%10;
		x=x chuyi 10;
	}
	f[k+1][1] = 1;
	for (int i=k+1;i>=2;i--)
		for (int j=0;j<=1;j++)
			for (int r=0;r<=9;r++)
			{
				if (j==1 && r>y[i-1]) continue;
				f[i-1][j!=0 && (r==y[i-1])] += f[i][j];
				g[i-1][j!=0 && (r==y[i-1])] += g[i][j] + f[i][j] * r;
			}
	return g[1][0]+g[1][1];
}

l ,r;

solve(r) - solve(l-1);
