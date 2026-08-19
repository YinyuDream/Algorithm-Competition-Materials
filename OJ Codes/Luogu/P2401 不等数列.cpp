#include<cstdio>
using namespace std;
int n,k;
const int maxn=1001,MOD=2015;
int dp[maxn][maxn];
int main(){
	scanf("%d%d",&n,&k);
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i;j++)
			{
				dp[i][j]=(dp[i-1][j]*(j+1))%MOD;
				if(j!=0)dp[i][j]=(dp[i-1][j-1]*(i-j)+dp[i][j])%MOD;
			}
	printf("%d",dp[n][k]);
	return 0;
}
