#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
const int len=20;
int m,n,s,e;
int a[maxn],dp[maxn][len];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		dp[i][0]=a[i];
	for(int j=1;j<=len;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&e);
		int k=log(e-s+1)/log(2);
		printf("%d ",min(dp[s][k],dp[e-(1<<k)+1][k]));	
	}	
	return 0;
}