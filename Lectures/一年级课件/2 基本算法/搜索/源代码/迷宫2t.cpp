#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=100+10;
int n,m,t;
int book[maxn][maxn],mapp[maxn][maxn];//0表示可以走 
int qx,qy,zx,zy;
int cnt;
int fx[4]={0,0,1,-1};
int fy[4]={1,-1,0,0}; 
int ans=999999999;

int llen[maxn][maxn];//llen[i][j]表示(i,j)这个点到起点的最短距离。 

void dfs(int x,int y,int step)
{
	if(x==zx && y==zy)
	{
		//到达终点，方案数加1，往回尝试其他情况 
		cnt++; 
		if(step<ans)ans=step;
		return ;
	}
	
	//int len=abs(zx-x)+abs(zy-y)+step;
	//if(len>=ans)return ;
	
	if(llen[x][y]>step)llen[x][y]=step;
	else return ;
	//优化，如果走到(x,y)点的路径已经大于之前的，那么这条路就不是最优答案 
	
	
	for(int i=0;i<=3;i++)//尝试在(x,y)点时可能的方案数，即4个方向 
	{
		int nx=x+fx[i];//下个点的坐标。 
		int ny=y+fy[i];
		if(mapp[nx][ny]==0 && book[nx][ny]==0 && nx>0 && nx<=n && ny>0 && ny<=n)//如果可以走， 
		{
			book[nx][ny]=1;
			dfs(nx,ny,step+1);
			book[nx][ny]=0;
		}
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mapp[i][j]);
			llen[i][j]=999999999; 
		}
	 } 
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	
	//llen[qx][qy]=0;
	book[qx][qy]=1;
	dfs(qx,qy,0);
	if(cnt>0)printf("%d",ans);
	else printf("-1");
	return 0;
}
