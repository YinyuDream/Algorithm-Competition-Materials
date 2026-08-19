#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int T;
ll a[maxn],b[maxn],t1,t2,ans;//C(m,n)
ll inv[maxn],sum[maxn];
ll C(int x,int y,int p)
{
	if(y>x)return 0;
	return (sum[x]%p)*(inv[y]%p)*(inv[x-y]%p)%p;
}
ll lucas(ll x,ll y,ll p)//c(x,y)
{
	if(y==0)return 1;
	return lucas(x/p,y/p,p)*C(x%p,y%p,p)%p;
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		ll n,m,p;
		scanf("%lld%lld%lld",&n,&m,&p);
		m=m+n;
		inv[0]=sum[0]=inv[1]=sum[1]=1;
		for(int i=2;i<=p;i++)
		sum[i]=sum[i-1]*i%p;
		for(int i=2;i<=p;i++)
		inv[i]=((p-p/i)*inv[p%i])%p;
		for(int i=2;i<=p;i++)
		inv[i]*=inv[i-1],inv[i]%=p;
		printf("%lld\n",lucas(m,n,p));
	}
	return 0;
}
