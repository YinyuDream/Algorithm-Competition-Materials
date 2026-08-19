#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,l,r;
ll a[maxn],suml[maxn],sumr[maxn],ans[maxn];
int main(){
	freopen("cuvelia.in","r",stdin);
	freopen("cuvelia.out","w",stdout);
	scanf("%d",&n);
	r=n+1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		suml[i]=suml[i-1]+a[i];
	for(int i=n;i;i--)
		sumr[i]=sumr[i+1]+a[i];
	for(int i=1;i<=n;i++){
		if(i&1)ans[i]=ans[i-1]+sumr[r]-suml[l];
		else{
			ans[i]=ans[i-1]+sumr[r]-suml[l];
			ans[i]+=a[--r]-a[++l];
		} 
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
