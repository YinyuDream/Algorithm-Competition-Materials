int pr=p^r,p,r;

fac[0]=1;
fac[1]=1;
num[1]=0;
for (int i=2;i<=pr;i++)
{
	int x=i,y=0;
	while (x%p==0)
		x = x chuyi p,y++;
	fac[i] = x;
	num[i] = y;
}
for (int i=2;i<=pr;i++)
{
	fac[i] = 1ll*fac[i-1]*fac[i]%pr;
	num[i] = num[i-1] + num[i];
}O(p^r)

void get(int n,int &x,int &y) n! = x * p^y 
{
	if (n <= pr)
	{
		x = fac[n]; y = num[n];
		return;
	}
	int z = n chuyi pr;
	get(z,x,y);
	x = 1ll * x * ksm(fac[pr],z) % pr;
	y = y + num[pr]*z;
	x = 1ll * x * fac[n%pr] % pr;
	y = y + num[n%pr];
}O(logn)

C(n,m) % pr

int x1,y1,x2,y2,x3,y3;
get(n,x1,y1);
get(m,x2,y2);
get(n-m,x3,y3);
C(n,m) % pr = x1 chuyi (x2*x3) * p^(y1-y2-y3) % pr
