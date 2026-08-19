int bsgs(int a,int b,int p)
{
	int sp = int(sqrt(p));
	int x=1;//a^0 % p
	set<int> se;
	for (int i=0;i<sp;i++)
	{
		se.insert(x);
		x=1ll*x*a%p;
	}
	int y=kuaisumi(a,sp,p);
	y=kuaisumi(y,p-2,p);
	for (int i=0;i<=sp+2;i++)
	{
		if (se.count(b)!=0)
		{
			x = i*sp;
			y = kuaisumi(a,x,p);//a^(i*sqrt(p))
			while (y!=b)
			{
				x++;
				y=1ll*y*a%p;
			}
			return x;
		}
		b=1ll*b*y%p;
	}
	return -1;
}
