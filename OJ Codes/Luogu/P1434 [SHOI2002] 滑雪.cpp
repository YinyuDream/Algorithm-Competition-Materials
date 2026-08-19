#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int n,m,ans;
int mapp[maxn][maxn],dis[maxn][maxn];
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
int dfs(int x,int y)
{
	if(dis[x][y]!=0)return dis[x][y];
	dis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>n||nx<1||ny>m||ny<1||mapp[nx][ny]>=mapp[x][y])continue;
		dis[x][y]=max(dis[x][y],dfs(nx,ny)+1); 
	}
	return dis[x][y];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mapp[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}
