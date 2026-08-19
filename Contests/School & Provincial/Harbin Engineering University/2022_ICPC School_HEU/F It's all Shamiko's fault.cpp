#include<bits/stdc++.h>
using namespace std;
const int maxn=4e2+10;
int n,T,ans;
int a[maxn],b[maxn],sum_a[maxn][maxn],sum_b[maxn][maxn];
int dp[maxn][maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(dp,0,sizeof dp);
		memset(sum_a,0,sizeof sum_a);
		memset(sum_b,0,sizeof sum_b);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(dp[i][j]<=j*(sum_a[i-1][j-1]+a[i])+(i-j)*sum_b[i-1][j-1]){
					dp[i][j]=j*(sum_a[i-1][j-1]+a[i])+(i-j)*sum_b[i-1][j-1];
					sum_a[i][j]=sum_a[i-1][j-1]+a[i];
					sum_b[i][j]=sum_b[i-1][j-1];
				}
				if(dp[i][j]<=j*sum_a[i-1][j]+(i-j)*(sum_b[i-1][j]+b[i])){
					dp[i][j]=j*sum_a[i-1][j]+(i-j)*(sum_b[i-1][j]+b[i]);
					sum_a[i][j]=sum_a[i-1][j];
					sum_b[i][j]=sum_b[i-1][j]+b[i];
				}
			}
		}
		for(int i=0;i<=n;i++)
			ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}