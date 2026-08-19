#include<cstdio>
using namespace std;
int n;
int a[maxn],b[maxn],c[maxn];
int dp[maxn][3][3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i],&b[i],&c[i]);
	
	for(int i=3;i<=n;i++)
	{
		dp[i][1][2]=dp[i-1][2][1]+b[i];
		dp[i][1][3]=max(dp[i-1][3][1],dp[i-1][3][2])+c[i];
		dp[i][2][1]=max(dp[i-1][1][2],dp[i-1][1][3])+a[i];
		dp[i][2][3]=max(dp[i-1][3][1],dp[i-1][3][2])+c[i];
		dp[i][3][1]=max(dp[i-1][1][3],dp[i-1][1][2])+a[i];
		dp[i][3][2]=dp[i-1][2][3]+b[i];
	}
	
	return 0;
}
