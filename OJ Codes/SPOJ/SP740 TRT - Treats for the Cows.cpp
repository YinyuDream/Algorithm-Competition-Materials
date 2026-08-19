#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,a[maxn];
int dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			dp[i][i+len-1]=max(dp[i+1][i+len-1]+a[i]*(n-len+1),dp[i][i+len-2]+a[i+len-1]*(n-len+1));
		}
	}
	printf("%d",dp[1][n]);
	return 0;
} 