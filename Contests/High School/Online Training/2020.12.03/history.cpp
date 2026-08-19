#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int n;
ll jc[maxn],a[maxn],sum[maxn],jcinv[maxn],f[1010][1010];
ll qpow(ll a,ll b)
{
	if(!b)return 1;
	ll c=qpow(a,b/2);
	c=c*c%p;
	if(b&1)c=c*a%p;
	return c;
}
inline ll C(ll x,ll y)
{
	return jc[x]*jcinv[y]%p*jcinv[x-y]%p;
}
int main(){
	freopen("history.in","r",stdin);
	freopen("history.out","w",stdout);
	jc[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum[i]=(sum[i-1]+a[i])%p,jc[i]=jc[i-1]*i%p;
	jcinv[0]=1;
	for(int i=1;i<=n;i++)
		jcinv[i]=jcinv[i-1]*qpow(i,p-2)%p;
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r=l+len-1)
			for(int i=l+1;i<=r;i++)
				(f[l][r]+=f[l][i-1]*jc[r-i]%p*C(r-l-1,i-l-1)+f[i][r]*jc[i-l-1]%p*C(r-l-1,i-l-1)+((i-l<=r-i+1)?sum[i-1]-sum[l-1]:sum[r]-sum[i-1])*jc[r-l-1])%=p;
	printf("%lld\n",(f[1][n]*jcinv[n-1]%p+p)%p);
	return 0;
}
