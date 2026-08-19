#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15;
int n,m,k,ans=0x7fffffff; 
int dis[N][N];
int dep[N],dp[1<<N];
void dfs(int S)
{
	for(int i=1;i<=n;i++)
	{
		if(S&(1<<i-1))
		{
			for(int j=1;j<=n;j++)
			{
				if((not (S&(1<<j-1)))&&(dis[i][j]!=0x3f3f3f3f))
				{
					if(dp[S|(1<<j-1)]>dp[S]+dep[i]*dis[i][j])
					{
						int tmp=dep[j];
						dep[j]=dep[i]+1;
						dp[S|(1<<j-1)]=dp[S]+dep[i]*dis[i][j];
						dfs(S|(1<<j-1));
						dep[j]=tmp;
					}
				}
			}
		}
	} 
}
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=dis[v][u]=min(dis[v][u],w);
	}
	for(int i=1;i<=n;i++)
	{
		memset(dep,0x3f,sizeof dep);
		memset(dp,0x3f,sizeof dp);
		dep[i]=1;
		dp[1<<i-1]=0;
		dfs(1<<i-1);
		ans=min(ans,dp[(1<<n)-1]);
	}
	printf("%d",ans);
	return 0;
}