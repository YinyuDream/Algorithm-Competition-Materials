#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e3+10,mod=10007;
int T,n;
char a[maxn];
ll dp[maxn][maxn];
int main(){
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("\n%s",a+1);
		n=strlen(a+1);
		for(int i=1;i<=n;i++)
			dp[i][i]=1;
		for(int i=1;i<n;i++)
			dp[i][i+1]=dp[i][i]+dp[i+1][i+1]+(a[i]==a[i+1]);
		for(int len=3;len<=n;len++)
			for(int l=1;l+len-1<=n;l++)
				dp[l][l+len-1]=dp[l+1][l+len-1]+dp[l][l+len-2]-dp[l+1][l+len-2]+(a[l]==a[l+len-1])*(dp[l+1][l+len-2]+1),
				dp[l][l+len-1]=(dp[l][l+len-1]+mod)%mod;
		printf("Case %d: %lld\n",j,(dp[1][n]+mod)%mod);
	}
	return 0;
}
