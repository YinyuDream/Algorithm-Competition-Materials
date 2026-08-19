#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int mo=999999599;

int v,n,m,prime_list[4]={2,13,5281,7283};

int fac[10000];

int mul(int a,int b,int mo)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

void get(int n,int &x,int &y,int p)
{
	if (n<p)
	{
		x=fac[n];
		y=0;
		return;
	}
	get(n/p,x,y,p);
	x=x*mul(fac[p],n/p,p)%p;
	y+=n/p;
	x=x*fac[n%p]%p;
}

int solve(int n,int m,int p)
{
	fac[0]=1;
	for (int a=1;a<p;a++)
		fac[a]=fac[a-1]*a%p;
	fac[p]=fac[p-1];
	int x1,y1,x2,y2,x3,y3;
	get(n,x1,y1,p);
	get(m,x2,y2,p);
	get(n-m,x3,y3,p);
	if (y1>y2+y3) return 0;
	return 1ll*x1*mul(x2,p-2,p)*mul(x3,p-2,p)%p;
}

int main()
{
	scanf("%d%d%d",&v,&n,&m);
	int n1=1,m1=0;
	for (int a=0;a<4;a++)
	{
		int n2=prime_list[a],m2=solve(n,m,prime_list[a]);
		if (n1<n2) swap(n1,n2),swap(m1,m2);
		while (m1%n2!=m2)
			m1+=n1;
		n1=n1*n2;
	}
	printf("%d\n",mul(v,m1,mo));

	return 0;
}
