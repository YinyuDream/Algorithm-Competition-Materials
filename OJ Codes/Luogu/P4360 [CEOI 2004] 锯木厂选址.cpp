#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,ans=0x7f7f7f7f;
int a[maxn],cost[maxn],f[maxn],d[maxn],sum[maxn];
int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&d[i]),
		sum[i]=sum[i-1]+a[i];
	cost[n]=a[n]*d[n];
	for(int i=n-1;i>=1;i--)
		d[i]+=d[i+1],cost[i]=cost[i+1]+a[i]*d[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[i]=min(f[i],cost[1]-cost[i]-sum[i-1]*d[i]+cost[i+1]-cost[j]-(sum[j-1]-sum[i])*d[j]+cost[j+1]),
			ans=min(ans,f[i]);
	printf("%d",ans);
	return 0;
}
