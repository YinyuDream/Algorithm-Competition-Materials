#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=500;
int n,m,k,qx,qy,zx,zy;
int mapp[maxn][maxn],book[maxn][maxn],cnt[maxn][maxn],dis[maxn][maxn];
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
struct node{
	int x,y,step;
	node(int x1,int y1,int step1){
		x=x1;y=y1;step=step1;
	}
};
queue<node>q;
void bfs()
{
	q.push(node(qx,qy,0));
	book[qx][qy]=1,cnt[qx][qy]=1;
	while(q.size())
	{
		node p=q.front();
		q.pop();
		for(int i=0;i<=3;i++)
		{
			int nx=p.x+dx[i],ny=p.y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||mapp[nx][ny]==1)continue;
			if(book[nx][ny]==1&&dis[nx][ny]==dis[p.x][p.y]+1)cnt[nx][ny]+=cnt[p.x][p.y];
			if(book[nx][ny]==0)
			{
				book[nx][ny]=1;
				cnt[nx][ny]=cnt[p.x][p.y];
				dis[nx][ny]=p.step+1;
				q.push(node(nx,ny,p.step+1));
			}
		}
	}
	printf("%d\n%d",dis[zx][zy],cnt[zx][zy]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		mapp[p][q]=1;
	}
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	bfs();
	return 0;
}
