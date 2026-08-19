int exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1;y=0;
		return a;
	}
	int xp,yp;
	int g=exgcd(b,a%b,xp,yp);
	x = yp;
	y = xp-a chuyi b * yp;
	return g;
}
