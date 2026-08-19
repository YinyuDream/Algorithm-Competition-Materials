#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
ll n,m,ans;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll qpow(ll a,ll b)
{
	if(b==0)return 1;
	ll c=qpow(a,b/2);
	c=c*c%p;
	if(b&1)c=c*a%p;
	return c;
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			ll t=qpow(gcd(i,j),n);
			for(ll k=1;k<=i*j;k++)
				if(gcd(i,k)==1&&gcd(j,k)==1)
					(ans+=t*k)%=p;
		}
	printf("%lld",ans);
	return 0;
}
