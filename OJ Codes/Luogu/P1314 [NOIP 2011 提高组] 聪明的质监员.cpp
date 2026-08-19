#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,l[maxn],r[maxn];
ll L,R,s,ans=1ll<<60,w[maxn],v[maxn],sum_cnt[maxn],sum_val[maxn];
ll check(ll x)
{
	ll num=0;
	for(int i=1;i<=n;i++)
		if(w[i]>=x)
		sum_cnt[i]=sum_cnt[i-1]+1,
		sum_val[i]=sum_val[i-1]+v[i];
		else
		sum_cnt[i]=sum_cnt[i-1],
		sum_val[i]=sum_val[i-1];
	for(int i=1;i<=m;i++)
		num+=(sum_cnt[r[i]]-sum_cnt[l[i]-1])*(sum_val[r[i]]-sum_val[l[i]-1]);
	return num;
}
int main(){
	scanf("%d%d%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&w[i],&v[i]),
		R=max(R,w[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]);
	while(L<=R)
	{
		ll mid=(L+R)/2,t=check(mid);
		ans=min(ans,abs(t-s));
		if(t>s)L=mid+1;
		else if(t<s)R=mid-1;
		else break;
	}
	printf("%lld",ans);
	return 0;
}
