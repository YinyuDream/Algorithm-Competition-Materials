#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
ll n;
ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}
struct fac{//a/b
	ll a,b;
	fac(){}
	fac(ll _a,ll _b){a=_a,b=_b;}
	void pt(){
		ll c=a/b,t=log10(c)+1,s=log10(b)+1;
		for(int i=1;i<=t;i++)
			printf(" ");
		printf("%lld\n%lld",a%b,c);
		for(int i=1;i<=s;i++)
		printf("-");
		puts("");
		for(int i=1;i<=t;i++)
			printf(" ");
		printf("%lld",b);
	}
};
fac operator+(fac x,fac y)
{
	ll t=x.b*y.b/gcd(x.b,y.b);
	fac z=fac(x.a*(t/x.b)+y.a*(t/y.b),t);
	t=gcd(z.a,z.b);
	if(t!=1)z.a/=t,z.b/=t;
	return z;	
}
fac f[maxn];
int main(){
	f[0]=fac(0,1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+fac(n,i);
	f[n].pt();
	return 0;
}
