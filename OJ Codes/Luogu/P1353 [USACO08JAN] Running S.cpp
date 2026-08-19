#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10,maxm=510;
int d[maxn],dp[maxn][maxm][2];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	//dp[1][1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]+d[i]),
			dp[i][j][0]=max(dp[i][j][0],max(dp[i-1][j-1][1],dp[i-1][j+1][0]));
		dp[i][0][0]=dp[i-1][1][0];
	}
	printf("%d",dp[n][0][0]);
}
