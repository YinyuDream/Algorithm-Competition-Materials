int prime[233],pcnt;
bool not_prime[23333];
void xxs(int n)
{
	not_prime[1]=true;
	for (int a=2;a<=n;a++)
	{
		if (not_prime[a] == false) prime[++pcnt] = a;
		for (int b=1;b<=pcnt;b++)
		{
			int v=a*prime[b];
			if (v>n) break;
			not_prime[v] = true;
			if (a % prime[b] == 0) break;
		}
	}
}
