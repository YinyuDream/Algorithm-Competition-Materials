#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
int n,m;
char a[maxn];
ll dp[maxn][maxn];
int main(){
	scanf("%s\n%d",a+1,&m);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int i=1;i<n;i++)
		dp[i][i+1]=dp[i][i]+dp[i+1][i+1]+(a[i]==a[i+1]);
	for(int len=3;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
			dp[l][l+len-1]=dp[l+1][l+len-1]+dp[l][l+len-2]-dp[l+1][l+len-2]+(a[l]==a[l+len-1])*dp[l+1][l+len-2];
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",dp[l][r]);
	}
	return 0;
}