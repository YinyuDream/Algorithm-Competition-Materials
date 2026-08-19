#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=65;
int n,m;
int dis[maxn][maxn];
int dp[maxn][maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		dis[u][v]=1;
		dp[u][v][0]=1;
	}
	for(int p=1;p<=64;p++)
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				for(int j=1;j<=n;j++)
					if(dp[i][k][p-1]&&dp[k][j][p-1])
						dp[i][j][p]=1,dis[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	printf("%d\n",dis[1][n]);
	return 0;
}
