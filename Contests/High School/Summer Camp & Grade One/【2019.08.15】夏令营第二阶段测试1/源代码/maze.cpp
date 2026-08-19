#include<cstdio>
using namespace std;

const int maxn=110;
int n,m,k,qx,qy,zx,zy,ans=1e9,cnt;
int mapp[maxn][maxn],len[maxn][maxn];
bool book[maxn][maxn];

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y,int step)
{
	len[x][y]=step;
	if(x==zx&&y==zy)
	{
		if(ans>step)
		{
			ans=step;
			cnt=1;
		}
		else if(ans==step)
			cnt++;
		else;
		return;
	}
	for(int i=0;i<=3;i++)
	{
		int ddx=x+dx[i],ddy=y+dy[i];
		if(ddx>0&&ddy>0&&ddx<=n&&ddy<=m&&step+1<=len[ddx][ddy]&&mapp[ddx][ddy]==0)
		{
			book[ddx][ddy]=1;
			dfs(ddx,ddy,step+1);
			book[ddx][ddy]=0;
		}
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int x1,y1;
		scanf("%d%d",&x1,&y1);
		mapp[x1][y1]=1;
	}
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)len[i][j]=1e9;
	}
	book[qx][qy]=1;
	dfs(qx,qy,0);
	printf("%d\n%d",ans,cnt);
	return 0;
}
