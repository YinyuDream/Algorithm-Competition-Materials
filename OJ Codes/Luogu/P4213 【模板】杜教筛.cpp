#include<cstdio>
#include<map>
using namespace std;
const int maxn=7e6+10;
typedef long long ll;
ll prime[maxn],not_prime[maxn],cnt;
ll miu_sum[maxn],phi_sum[maxn];
int T;
map<ll,ll>miu;
map<ll,ll>phi;
void pre_work()
{
	miu_sum[1]=phi_sum[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!not_prime[i]){
			prime[++cnt]=i;
			phi_sum[i]=i-1;
			miu_sum[i]=-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prime[j]>=maxn)break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]!=0)
			phi_sum[i*prime[j]]=phi_sum[i]*phi_sum[prime[j]],
			miu_sum[i*prime[j]]=miu_sum[i]*miu_sum[prime[j]];
			else
			phi_sum[i*prime[j]]=phi_sum[i]*prime[j],
			miu_sum[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=2;i<maxn;i++)
		phi_sum[i]+=phi_sum[i-1],
		miu_sum[i]+=miu_sum[i-1];
}
ll get_sum_miu(ll x)
{
	if(x<maxn)return miu_sum[x];
	if(miu[x])return miu[x]; 
	ll ans=0;
	for(int l=2,r;l<=x;l=r+1)
	{
		r=x/(x/l);
		ans+=(r-l+1)*get_sum_miu(x/l);
	}
	return miu[x]=1-ans;
}
ll get_sum_phi(ll x)
{
	if(x<maxn)return phi_sum[x];
	if(phi[x])return phi[x]; 
	ll ans=0;
	for(int l=2,r;l<=x;l=r+1)
	{
		r=x/(x/l);
		ans+=(r-l+1)*get_sum_phi(x/l);
	}
	return phi[x]=x*(x+1)/2-ans;
}
int main(){
	pre_work();
	scanf("%d",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld %lld\n",get_sum_phi(n),get_sum_miu(n));
	}
	return 0;
}
