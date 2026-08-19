#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e6+10;
const ll p=998244353;
int n,k,pos;
ll ans,a[maxn],sum[maxn],sum2[maxn];
ll get_sum(int l,int r,ll plus)
{
	if(l>r)return 0;
	return (sum2[r]-sum2[l-1]+2*plus*(sum[r]-sum[l-1])%p+plus*plus%p*(r-l+1))%p;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]+a[i])%p;
		sum2[i]=(sum2[i-1]+a[i]*a[i])%p;
	}
	for(int i=1;i<=n+1;i++)
		if(a[i-1]<0&&a[i]>=0)
			pos=i;
	if(pos==0)pos=1;
	ans=get_sum(1,n,1)%p;
	for(int i=2;i<=k;i++)
	{
		while(-2*a[pos-1]<=i&&pos>=2)pos--;
		ans+=(get_sum(1,pos-1,1)+get_sum(pos,n,i));
		ans%=p;
	}
	printf("%lld",(ans+p)%p);
	return 0;
}