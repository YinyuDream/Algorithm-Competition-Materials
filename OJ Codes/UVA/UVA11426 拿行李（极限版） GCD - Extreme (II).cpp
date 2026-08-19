#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=4e6+10;
ll n;
ll prime[maxn],not_prime[maxn],phi[maxn],cnt;
ll ans[maxn];
void get_phi()
{
	phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!not_prime[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prime[j]>maxn)break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]!=0)
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else
			phi[i*prime[j]]=phi[i]*prime[j];
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<maxn;i++)
		phi[i]+=phi[i-1];
}
ll query(ll x)
{
	ll ans=0;
	for(ll l=1,r;l<=x;l=r+1)
	{
		r=min(x/(x/l),x);
		ans+=(phi[r]-phi[l-1])*(x/l)*(x/l);
	}
	return ans;
}
int main(){
	get_phi();
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)break;
		printf("%lld\n",(query(n)-n*(n+1)/2)/2);
	}
	return 0;
}