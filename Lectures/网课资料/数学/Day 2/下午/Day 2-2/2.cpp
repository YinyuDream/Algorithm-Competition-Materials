int prime[233],pcnt;
int phi[23333],mu[23333];
bool not_prime[23333];

void xxs(int n)
{
	not_prime[1]=true;
	phi[1] = 1; mu[1] = 1;
	for (int a=2;a<=n;a++)
	{
		if (not_prime[a] == false) 
		{
			prime[++pcnt] = a;
			phi[a] = a-1; mu[a] = -1;
		}
		for (int b=1;b<=pcnt;b++)
		{
			int v=a*prime[b];
			if (v>n) break;
			not_prime[v] = true;
			if (a % prime[b] == 0)
			{
				phi[v] = phi[a] * prime[b];
				mu[v] = 0;
			}
			else
			{
				phi[v] = phi[a] * phi[prime[b]];
				mu[v] = mu[a] * mu[prime[b]];
			}
			if (a % prime[b] == 0) break;
		}
	}
}
