#include<cstdio>
#include<algorithm> 
using namespace std;
int ans,n;
int dp[5001][5001];
int a[5001],b[5001]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]!=b[j])dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j-1]+1;
	printf("%d",dp[n][n]);
	return 0;
}
