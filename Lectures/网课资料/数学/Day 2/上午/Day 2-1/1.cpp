int prime[8]={2,3,5,7,11,13,17,37};
bool miller_rabin(int n,int a)
{
	int d=n-1,r=0;
	while (d%2==0)
		d=d>>1,r++;
	int z=ksm(a,d,n);
	if (z==1) return true;
	for (int i=0;i<r;i++)
	{
		if (z==n-1) return true;
		z=1ll*z*z%n;
	}
	return false;
}
bool check(int n)
{
	if (n<2) return false;
	for (int a=0;a<8;a++)
	{
		if (n == prime[a]) return true;
		if (n % prime[a] == 0) return false;
		if (!miller_rabin(n,prime[a])) return false;
	}
	return true;
}
