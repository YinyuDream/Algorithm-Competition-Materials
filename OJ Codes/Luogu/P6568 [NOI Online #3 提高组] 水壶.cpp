#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
int a[maxn],sum[maxn];
int main()
{
	//freopen("kettle.in","r",stdin);
	//freopen("kettle.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=k;i<=n;i++)
	ans=max(ans,sum[i]-sum[i-k-1]);
	printf("%d",ans);
	return 0;
}