int get_yuan_gen(int p)//O(phi(p))
{
	int phip = phi(p);
	for (int a=2;;a++)
	{
		bool able=true;
		for (int b=2;b*b<=phip && able;b++)
			if (phip%b==0)
			{
				if (kuaisumi(a,b,p)==1) able=false;
				if (kuaisumi(a,phip/b,p)==1) able=false;
			}
		if (able) return a;
	}
}
