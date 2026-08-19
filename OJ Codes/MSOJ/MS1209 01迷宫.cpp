#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m,cnt;
int dx[4]={1,0,-1,0},
	dy[4]={0,1,0,-1};
int size[maxn*maxn],pos[maxn][maxn],mapp[maxn][maxn],book[maxn][maxn];
void dfs(int x,int y,int _cnt)
{
	size[_cnt]++;
	pos[x][y]=_cnt;
	book[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>0&&nx<=n&&ny>0&&ny<=n&&mapp[x][y]^mapp[nx][ny]==1&&book[nx][ny]==0)
		dfs(x+dx[i],y+dy[i],_cnt);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char ch;
			scanf(" %c",&ch);
			mapp[i][j]=ch-'0';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(book[i][j]==0)
				dfs(i,j,++cnt);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",size[pos[x][y]]);
	}
	return 0;
}