#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
ll prime[maxn],not_prime[maxn],cnt,p;
ll phi_sum[maxn];
map<ll,ll>phi;
void pre_work()
{
	phi_sum[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!not_prime[i]){
			prime[++cnt]=i;
			phi_sum[i]=i-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prime[j]>=maxn)break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]!=0)
			phi_sum[i*prime[j]]=phi_sum[i]*phi_sum[prime[j]];
			else
			phi_sum[i*prime[j]]=phi_sum[i]*prime[j];
			if(i%prime[j]==0)break;
		}
	}
	for(int i=2;i<maxn;i++)
		phi_sum[i]=phi_sum[i]*i*i+phi_sum[i-1],
		phi_sum[i]%=p;
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
		ans%=p;
	}
	return phi[x]=(x*(x+1)/2-ans+p)%p;
}
ll query()
{
	ll ans=0;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans+=(get_sum_phi(r)-get_sum_phi(l-1))*(n/l);
		ans=(ans+p)%p;
	}
	return ans%p;
}
int main(){
	
	scanf("%d%d",&p,&n);
	pre_work();
	printf("%lld",query());
}
