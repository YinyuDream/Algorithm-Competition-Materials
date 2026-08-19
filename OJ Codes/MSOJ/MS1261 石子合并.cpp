#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=200;
int n,m,ansmax,ansmin=0x7f7f7f7f;
int a[maxn],sum[maxn];
int dp[maxn][maxn],dp2[maxn][maxn];
int main(){
	scanf("%d",&n);
	m=n<<1;
	memset(dp2,0x3f,sizeof(dp2));
	for(int i=1;i<=m;i++)
		dp2[i][i]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[n+i]=a[i];
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+a[i];
	for(int len=1;len<n;len++)
		for(int i=1;i<m;i++)
			for(int j=i;j<len+i&&i+len<m;j++)
				dp[i][i+len]=max(dp[i][i+len],dp[i][j]+dp[j+1][i+len]+sum[i+len]-sum[i-1]),
				dp2[i][i+len]=min(dp2[i][i+len],dp2[i][j]+dp2[j+1][i+len]+sum[i+len]-sum[i-1]);
	for(int i=1;i<=n;i++)
		ansmax=max(ansmax,dp[i][n+i-1]),
		ansmin=min(ansmin,dp2[i][n+i-1]);
	printf("%d\n%d\n",ansmin,ansmax);		
	return 0;
}
