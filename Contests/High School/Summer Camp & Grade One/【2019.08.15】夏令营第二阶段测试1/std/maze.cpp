#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=100+10;
int n,m,k;
int mapp[maxn][maxn],book[maxn][maxn];
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int qx,qy,zx,zy;
int cnt,minn=0x7f7f7f7f;

int len[maxn][maxn];

int jdz(int x)
{
	if(x>=0)return x;
	return x*(-1);
}
void dfs(int x,int y,int step)
{
	if(x==zx&& y==zy)
	{
		if(step<minn)
		{
			cnt=1;minn=step;
		}
		else if(step==minn)cnt++;
		return ;
	}
	
	//最优性剪枝，90分；
	int lenn=jdz(zx-x)+jdz(zy-y)+step;//到终点曼哈顿距离+当前点到起点步数 
	if(lenn>minn)return;//我预测的最优值 比曾求出的minn大，则这条路求不出最优值，返回。 
	
	//可行性剪枝 
	//每个点都记录到起点的最优值，如果当前走的路更短，就更新最优值，否则就不是最优解。 
	if(step<=len[x][y])len[x][y]=step; //要求最短路条数，=就不能丢。 
	else return;
	
	for(int i=0;i<=3;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];
		
		if(nx>0 && nx<=n && ny>0 && ny<=m &&mapp[nx][ny]==0 && book[nx][ny]==0)
		{
			book[nx][ny]=1;
			dfs(nx,ny,step+1);
			book[nx][ny]=0;
		}
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int t1,t2;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&t1,&t2);
		mapp[t1][t2]=1;
	}
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	memset(len,127,sizeof(len));
	
	book[qx][qy]=1;
	dfs(qx,qy,0);
	if(cnt>0)	printf("%d\n%d\n",minn,cnt);
	else printf("No Solution!");
	return 0;
}
