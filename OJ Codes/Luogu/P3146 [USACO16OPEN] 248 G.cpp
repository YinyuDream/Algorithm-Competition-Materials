#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=250;
int n,a[maxn],ans;
int dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			for(int j=i;j<i+len-1;j++){
				if(dp[i][j]==dp[j+1][i+len-1]){
					dp[i][i+len-1]=max(dp[i][j]+1,dp[i][i+len-1]);
					ans=max(ans,dp[i][i+len-1]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
