
int n,z[110][110];

int gauss()
{
	int x=1;
	for (int a=1;a<=n;a++)
	{
		for (int b=a+1;b<=n;b++)
		{
			while (z[b][a]!=0)
			{
				int k = z[a][a] / z[b][a];
				for (int c=1;c<=n;c++)
					z[a][c] = z[a][c] - z[b][c] * k;
				for (int c=1;c<=n;c++)
					swap(z[a][c],z[b][c]);
				x=-x;
			}
		}
	}
	for (int a=1;a<=n;a++)
		x=x*z[a][a];
	return x;
}
