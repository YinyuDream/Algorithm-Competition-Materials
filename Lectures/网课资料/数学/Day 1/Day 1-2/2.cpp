double z[110][110];
int n;

double gauss()
{
	double x=1;
	for (int a=1;a<=n;a++)
	{
		for (int b=a+1;b<=n;b++)
			if (fabs(z[b][a]) > fabs(z[a][a]))
			{
				x=-x;
				for (int c=1;c<=n;c++)
					swap(z[b][c],z[a][c]);
			}
		if (fabs(z[a][a]) <= 1e-8) return 0.0;
		for (int b=a+1;b<=n;b++)
		{
			double k = z[b][a] / z[a][a];
			for (int c=1;c<=n;c++)
				z[b][c] = z[b][c] - z[a][c] * k;
		}
	}
	for (int a=1;a<=n;a++)
		x=x*z[a][a];
	return x;
}
