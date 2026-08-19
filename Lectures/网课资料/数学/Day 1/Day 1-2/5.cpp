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


matrix ksm(matrix x,int y)
{
	if (y==0) 
	{
		matrix z;
		z.n=z.m=x.n;
		for (int a=1;a<=z.n;a++)
			z.z[a][a] = 1;
		return z;
	}
	matrix z = ksm(x,y>>1);
	z = z*z;
	if (y%2==1) z=z*x;
	return z;
}

int main()
{
	m1 = [1,0];
	m2 = [[1,1],[1,0]];
	m1 * ksm(m2,n-1) = [fn,fn-1];
}
