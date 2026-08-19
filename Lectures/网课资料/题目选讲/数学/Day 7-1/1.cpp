bool miller_rabin(int n,int a)
{
	int d=n-1,r=0;
	while (d%2==0)
		d=d/2,r++;
	int x=kuaisumi(a,d,n);//a^d % n
	if (x==1) return true;
	for (int i=0;i<r;i++)//logn
	{
		//x = a^(d*2^i) % n
		if (x==n-1) return true;
		x=1ll*x*x%n;
	}
	return false;
}

int prime[10]={0,2,3,5,7,11,23,37,47};

bool is_prime(int n)//O(klogn)
{
	for (int a=1;a<=8;a++)//O(k)
		if (!miller_rabin(n,prime[a])) return false;
	return true;
}
