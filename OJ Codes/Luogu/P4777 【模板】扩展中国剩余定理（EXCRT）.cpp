#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e5+10;//x≡b[i](mod a[i])
typedef long long ll;
ll n,a[maxn],b[maxn];
ll mul(ll a,ll b,ll p)
{
	ll ans=0;
	while(b!=0){
		if(b&1)ans+=a,ans%=p;
		a=(a+a)%p;
		b>>=1; 
	}
	return ans;
}
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1;y=0;return a;
	}
	ll gcd=ex_gcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
	return gcd;
}
int main(){
	//freopen("P4777_14.in","r",stdin);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld%lld",&a[i],&b[i]),b[i]%=a[i];
	for(int i=2;i<=n;i++)
	{	
		ll x,y,gcd=ex_gcd(a[i-1],a[i],x,y);
		ll c=(b[i]-b[i-1]%a[i]+a[i])%a[i];
		x=mul(x,c/gcd,a[i]/gcd);
		b[i]=x*a[i-1]+b[i-1];
		a[i]*=a[i-1]/gcd;
		b[i]=(b[i]%a[i]+a[i])%a[i];
	}
	printf("%lld\n",b[n]);
	return 0;
}