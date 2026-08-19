#include<cstdio>
using namespace std;
const int maxn=55;
int n,m;
int mapp[maxn][maxn];
int book[maxn][maxn][6][6],pre[maxn][maxn][6][6];//骰子在(x,y),上面为i，左侧面为j的情况 
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
struct node{
	int x,y,a,b;
};
queue<node>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",mapp[i][j]);
	q.push(node(1,1,1,2));
	while(q.size())
	{
		node t=q.top();
		q.pop();
		for(int i=0;i<=3;i++)
		{
			int nx=t.x+dx,ny=t.y+dy;
			if(nx<1||ny<1||nx>n||ny>m||mapp[nx][ny]==1)continue;
			
		}
	}
	return 0;
}
