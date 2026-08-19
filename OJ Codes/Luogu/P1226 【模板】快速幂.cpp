#include<cstdio>
#define ll long long
using namespace std;
ll n,m,p;
ll fast_pow(ll a,ll b,ll mod)
{
	if(b==0)return 1ll%mod;
	ll c=fast_pow(a,b/2,mod);
	c=c*c%mod;
	if(b&1)c=a*c%mod;
	return c%mod;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	printf("%lld^%lld mod %lld=%lld",n,m,p,fast_pow(n,m,p));
	return 0;
}