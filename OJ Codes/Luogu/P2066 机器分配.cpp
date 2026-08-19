#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e2+10;
int n,m;
int dp[maxn][maxn],f[maxn][maxn],a[maxn][maxn];
void pt(int x,int y)
{
	if(x>1)pt(x-1,y-f[x][y]);
	printf("%d %d\n",x,f[x][y]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=m;k++)
				if(j-k>=0)
				{
					if(dp[i][j]<dp[i-1][j-k]+a[i][k])
					dp[i][j]=dp[i-1][j-k]+a[i][k],
					f[i][j]=k;
					else if(dp[i][j]==dp[i-1][j-k]+a[i][k])
					f[i][j]=k;
				}
	printf("%d\n",dp[n][m]);
	pt(n,m);
	return 0;
}
