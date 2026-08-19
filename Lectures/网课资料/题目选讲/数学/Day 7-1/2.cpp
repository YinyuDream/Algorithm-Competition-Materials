int get_yuan_gen(int p)//O(phi(p))
{
	int phip = phi(p);
	for (int a=2;;a++)
	{
		int x=1;//a^0 % p
		for (int b=0;b<phip;b++)
		{
			z[b]=x;
			x=1ll*x*a%p;
		}
		sort(z,z+phip);
		bool able=true;
		for (int b=1;b<phip;b++)
			if (z[b]==z[b-1]) able=false;
		if (able) return a;
	}
}
