int bsgs(int a,int b,int p) a^x % p = b
{
	int sp = int(sqrt(p));

	z[0] = 1;
	for (int i=1;i<sp;i++)
		z[i] = 1ll*z[i-1]*a%p;

	for (int i=0;i<sp;i++)
		if (z[i] % p == b) return i;
	sort(z,z+sp);

	int asp = ksm(a,sp,p);

	for (int i=2,l=sp,r=sp+sp-1;l<=n;l+=sp,r+=sp,i++)
	{
		int div = ksm(asp,i-1,p);
		div = ksm(div,p-2,p);
		int v = 1ll*b*div%p;
		binary();
	}
	return -1;
}
