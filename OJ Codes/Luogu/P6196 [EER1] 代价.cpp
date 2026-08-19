#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n;
ll a[maxn],dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)
		scanf("%lld",&a[i]);
	a[1]=a[n+2]=1;
	memset(dp,0x7f,sizeof dp);
	for(int i=1;i<=n;i++)
		dp[i][i+2]=a[i]*a[i+1]*a[i+2],dp[i][i+1]=0;
	for(int len=4;len<=n+2;len++)
		for(int l=1;l+len-1<=n+2;l++)
			for(int k=l+1;k<=l+len-2;k++)
				dp[l][l+len-1]=min(dp[l][l+len-1],dp[l][k]+dp[k][l+len-1]+a[l]*a[k]*a[l+len-1]);
	printf("%lld",dp[1][n+2]);
	return 0;
}