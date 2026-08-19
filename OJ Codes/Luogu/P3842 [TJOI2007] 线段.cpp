#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2e4+10;
int n,ans=0x7f7f7f7f;
int l[maxn],r[maxn],dp[maxn][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	if(n==1){
		puts("0");
		return 0;
	}
	dp[1][0]=2*r[1]-l[1]-1,dp[1][1]=r[1]-1;
	for(int i=2;i<n;i++){
		dp[i][0]=min(abs(l[i-1]-r[i])+abs(l[i]-r[i])+dp[i-1][0],abs(r[i-1]-r[i])+abs(l[i]-r[i])+dp[i-1][1])+1;
		dp[i][1]=min(abs(l[i-1]-l[i])+abs(l[i]-r[i])+dp[i-1][0],abs(r[i-1]-l[i])+abs(l[i]-r[i])+dp[i-1][1])+1;
	}
	if(l[n-1]<=l[n])ans=min(ans,dp[n-1][0]+n-l[n-1]+1);
	else if(l[n-1]>l[n])ans=min(ans,dp[n-1][0]+l[n-1]-2*l[n]+n+1);
	if(r[n-1]<=l[n])ans=min(ans,dp[n-1][1]+n-r[n-1]+1);
	else ans=min(ans,dp[n-1][1]+r[n-1]-2*l[n]+n+1);
	printf("%d",ans);
	return 0;
}