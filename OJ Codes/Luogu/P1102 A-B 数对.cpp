#include<cstdio>
#include<algorithm>
#define int long long
const int maxn=2e5+10;
using namespace std;
int a[maxn];
int n,c,ans;
signed main(){
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans+=upper_bound(a+1,a+n+1,a[i]+c)-lower_bound(a+1,a+n+1,a[i]+c);
	printf("%lld",ans);	
}