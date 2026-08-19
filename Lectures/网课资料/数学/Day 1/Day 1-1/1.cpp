cmath pow(x,y)

y>>1 = y/2

int ksm(int x,int y,int p)
{
	if (y==0) return 1;
	int z = ksm(x,y>>1,p);
	z = 1ll*z*z%p;
	if (y%2==1) z=1ll*z*x%p;
	return z;
}
int ksm(int x,int y,int p)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=1ll*ans*x%p;
		x=1ll*x*x%p;
		y>>=1;
	}
	return ans;
}
