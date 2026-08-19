#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1200;
int m,n,cnt,ans=1e9;
int mapp[maxn][maxn];
bool book[maxn][maxn];
bool bo,c;
int xy1[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int va(int a,int b,int c,int d)
{
	if(mapp[a][b]!=mapp[c][d])return 1;
	else return 0;
}
void dfs(int x,int y)
{
	if(x==m&&y==m)
	{
		c=1;
		if(cnt<ans)ans=cnt;
		return ;
	}
	for(int i=0;i<=3;i++)
	{
		int ddx=x+xy1[i][0];
		int ddy=y+xy1[i][1];
		if(ddy>m||ddx>m||ddx<1||ddy<1)continue;
		if(mapp[ddx][ddy]!=-1&&book[ddx][ddy]==0)
		{
			bo=0;
			if(va(x,y,ddx,ddy))cnt++;
			book[ddx][ddy]=1;
			dfs(ddx,ddy);
			if(va(x,y,ddx,ddy))cnt--;
			book[ddx][ddy]=0;
		}
		if(mapp[ddx][ddy]==-1&&book[ddx][ddy]==0&&bo==0)
		{
			bo=1;
			book[ddx][ddy]=1;
			cnt+=2;
			mapp[ddx][ddy]=mapp[x][y];
			dfs(ddx,ddy);
			cnt-=2;
			book[ddx][ddy]=0;
			mapp[ddx][ddy]=-1;
		}
	}
	
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			mapp[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		int x,y,color;
		scanf("%d%d%d",&x,&y,&color);
		mapp[x][y]=color;
	}
	dfs(1,1);
	if(c!=0)printf("%d",ans);
	else printf("-1");
}
