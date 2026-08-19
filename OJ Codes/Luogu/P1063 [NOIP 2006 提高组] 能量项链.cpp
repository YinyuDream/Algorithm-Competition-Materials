#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e2+10; 
int n,ans;
int dp[maxn][maxn];
struct node{
	int head,tail;
}a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].head),a[n+i].head=a[i].head;
	for(int i=2*n-1;i>=1;i--)
		a[i].tail=a[i+1].head;
	for(int i=1;i<=n;i++)
		for(int l=1;l<n*2;l++)
			for(int k=l;k<l+i&&l+i<n+n;k++)
				dp[l][l+i]=max(dp[l][l+i],dp[l][k]+dp[k+1][l+i]+a[l].head*a[k].tail*a[l+i].tail);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][i+n-1]);
	printf("%d",ans);
	return 0;
}
