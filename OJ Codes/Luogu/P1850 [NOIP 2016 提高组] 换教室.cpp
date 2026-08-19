#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,m,v,e;
int c[maxn],d[maxn];
double k[maxn];
int dis[maxn][maxn];
double dp[maxn][maxn][2];
void init()
{
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)
	scanf("%lf",&k[i]);
	for(int i=1;i<=e;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=dis[v][u]=min(dis[v][u],w);
	}
}
void floyd()
{
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=v;i++)
		dis[i][i]=dis[i][0]=dis[0][i]=0;			
}
void work()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j][0]=dp[i][j][1]=1e17;	
	dp[1][0][0]=dp[1][1][1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i][0][0]=dp[i-1][0][0]+dis[c[i-1]][c[i]];
		for(int j=1;j<=min(i,m);j++)
		{
			dp[i][j][0]=min(dp[i-1][j][0]+dis[c[i-1]][c[i]],
							dp[i-1][j][1]+k[i-1]*dis[d[i-1]][c[i]]+
							(1.0-k[i-1])*dis[c[i-1]][c[i]]);
			dp[i][j][1]=min(dp[i-1][j-1][0]+k[i]*dis[c[i-1]][d[i]]+(1.0-k[i])*dis[c[i-1]][c[i]],
							dp[i-1][j-1][1]+
							k[i-1]*k[i]*dis[d[i-1]][d[i]]+
							k[i-1]*(1.0-k[i])*dis[d[i-1]][c[i]]+
							(1.0-k[i-1])*k[i]*dis[c[i-1]][d[i]]+
							(1.0-k[i-1])*(1.0-k[i])*dis[c[i-1]][c[i]]);
		}
	}
}
void output()
{
	double ans=1e17;
	for(int i=0;i<=m;i++)
		ans=min(min(dp[n][i][0],dp[n][i][1]),ans);
	printf("%.2lf",ans);
}
int main(){
	init();
	floyd();
	work();
	output();
	return 0;
}
