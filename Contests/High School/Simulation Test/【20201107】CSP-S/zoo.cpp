#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,m,c,k,t,ans;
ll a[maxn],p[maxn],book[maxn];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]),t|=a[i];
	for(ll i=1,x,y;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		book[x]=1;
	}
	for(ll i=0;i<k;i++)
		if(t&(1ll<<i)||!book[i])
			ans++;
	printf("%lld\n",(1ll<<ans)-n);
	return 0;
}
