#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e3+10,mod=998244353;
int n,m;
int a[maxn][maxn];
long long ans=1,ans2=0,sum[maxn],dp[maxn][maxn];//前i行当前列x=2j-k的方案数,k:总数，j：当前列数总数 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]),sum[i]+=a[i][j],sum[i]%=mod; 
	for(int i=1;i<=n;i++)
		ans=(ans*(sum[i]+1))%mod;
	for(int i=1;i<=m;i++)
	{
		dp[0][n]=1; 
		for(int j=1;j<=n;j++)
			for(int k=-n;k<=n;k++)
				dp[j][k+n]=(dp[j-1][k+n]+dp[j-1][k+n-1]*a[j][i]%mod+dp[j-1][k+n+1]*(sum[j]-a[j][i]+mod)%mod)%mod; 
		for(int j=n+1;j<=n*2;j++)
			ans2=(dp[n][j]+ans2)%mod;
	}
	printf("%lld",(ans-1-ans2+mod)%mod);
	return 0;
}
