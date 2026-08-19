#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,R;
ll a[maxn],sum[maxn],tsum[maxn],k,l,r,ans;
void update(int pos,ll y,ll *t)
{
	for(int i=pos;i<=n;i+=i&(-i))
		t[i]+=y;
}
ll query(int x,ll *t)
{
	ll num=0;
	for(int i=x;i;i-=i&(-i))
		num+=t[i];
	return num;
}
bool check(ll x){
	for(int i=1;i<=n;i++)
		tsum[i]=sum[i];
	ll num=0;
	for(int i=1;i<=n;i++){
		ll t=query(min(i+R,n),tsum)-query(max(i-R-1,0),tsum);
		if(t<x){
			num+=x-t;
			update(min(i+R,n),x-t,tsum);
		}
	}
	return num<=k;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%lld",&n,&R,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		update(i,a[i],sum);
	r=2e18;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}
