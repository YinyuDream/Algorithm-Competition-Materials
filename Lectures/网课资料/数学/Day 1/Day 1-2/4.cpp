struct matrix
{
	int n,m;
	int z[233][233];
	matrix()
	{
		n=m=0;
		memset(z,0,sizeof(z));
	}
};

matrix operator*(const matrix &a,const matrix &b)
{
	matrix c;
	c.n = a.n;
	c.m = b.m;
	for (int i=1;i<=c.n;i++)
		for (int j=1;j<=c.m;j++)
			for (int k=1;k<=a.m;k++)
				c.z[i][j] = c.z[i][j] + a.z[i][k] * b.z[k][j];
	return c;
}
