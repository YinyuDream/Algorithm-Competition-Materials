#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,w[maxn][maxn],dp[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&w[i][j]);
	memset(dp,0x3f,sizeof dp);
	dp[1]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			dp[i]=min(dp[i],dp[j]+w[j][i]);
	printf("%d",dp[n]);
	return 0;
}
