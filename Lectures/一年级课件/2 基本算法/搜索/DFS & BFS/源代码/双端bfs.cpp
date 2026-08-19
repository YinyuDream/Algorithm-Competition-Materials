#include<cstdio>
#include<deque>
using namespace std;
const int maxn=110;
int n,sx,sy,ex,ey;
int mapp[maxn][maxn],book[maxn][maxn],dis[maxn][maxn];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct node{
	int x,y,step;
	node(int x1,int y1,int step1){
		x=x1,y=y1,step=step1;
	}
};
deque<node>q;
void bfs()
{
	q.push_back(node(sx,sy,0));
	book[sx][sy]=1;
	while(q.size())
	{
		node tmp=q.front();
		q.pop_front();
		for(int i=0;i<=3;i++)
		{
			int nx=tmp.x+dx[i],ny=tmp.x+dy[i];
			if(nx>n||nx<1||ny>n||ny<1||book[nx][ny]==1)continue;
			if(mapp[nx][ny]==mapp[tmp.x][tmp.y])book[nx][ny]=1,q.push_front(node(nx,ny,tmp.step)),dis[nx][ny]=dis[tmp.x][tmp.y];
			else book[nx][ny]=1,q.push_back(node(nx,ny,tmp.step+1)),dis[nx][ny]=dis[tmp.x][tmp.y]+1;
		}	
	}
}
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mapp[i][j]);
	bfs();
	printf("%d",dis[ex][ey]);
	return 0;
}
