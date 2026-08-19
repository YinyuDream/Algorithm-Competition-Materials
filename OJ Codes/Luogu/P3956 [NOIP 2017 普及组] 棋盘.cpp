#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int m,n,ans=0x7f7f7f7f;
int book[maxn][maxn],mapp[maxn][maxn],dis[maxn][maxn];
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int color,int step)
{
	if(step>=dis[x][y])return ;
	else dis[x][y]=step;
	if(x==m&&y==m){
		ans=dis[x][y];return ;
	}
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(book[nx][ny]==1||nx==0||nx>m||ny==0||ny>m)continue;
		if(mapp[nx][ny]!=0&&mapp[nx][ny]==color)
		{
			book[nx][ny]=1;
			dfs(nx,ny,mapp[nx][ny],step);
			book[nx][ny]=0;
		}
		else if(mapp[nx][ny]!=0&&mapp[nx][ny]!=color)
		{
			book[nx][ny]=1;
			dfs(nx,ny,mapp[nx][ny],step+1);
			book[nx][ny]=0;	
		}
		else if(mapp[nx][ny]==0&&mapp[x][y]!=0)
		{
			book[nx][ny]=1;
			dfs(nx,ny,mapp[x][y],step+2);
			book[nx][ny]=0;
		}
		else;
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		mapp[x][y]=c+1;
	}
	memset(dis,0x3f,sizeof dis);
	dfs(1,1,mapp[1][1],0);
	//printf("%d",ans);
	printf("%d",dis[m][m]!=0x3f3f3f3f?dis[m][m]:-1);
	return 0;
}