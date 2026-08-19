#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
ll p,b,n,ans;
map<ll,ll>z;
ll fast_pow(ll a,ll b,ll mod)
{
	if(b==0)return 1ll;
	ll c=fast_pow(a,b/2,mod);
	c=c*c%mod;
	if(b&1)c=a*c%mod;
	return c%mod;
}
ll BSGS(ll a,ll b,ll p)//a^x¡Ôb(mod p)
{
	ll t=sqrt(p),num=1;
	for(int i=1;i<=t;i++)
	{
		num=1ll*num*a%p,
		z[num]=i;
		if(num%p==b)return i;
	}
	ll q=fast_pow(a,t,p);
	for(int i=2;i<=t+1;i++)
	{
		ll s=fast_pow(q,i-1,p);
		s=fast_pow(s,p-2,p);
		if(z[b*s%p])return z[b*s%p]+(i-1)*t;	
	}
	return -1;
} 
int main(){
	scanf("%lld%lld%lld",&p,&b,&n);
	if((ans=BSGS(b,n,p))!=-1)printf("%lld",ans);
	else puts("no solution"); 
	return 0;
}
