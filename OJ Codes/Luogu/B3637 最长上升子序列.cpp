#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,a[maxn];
int dp[maxn];
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]<a[i])dp[i]=max(dp[j]+1,dp[i]);		
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
