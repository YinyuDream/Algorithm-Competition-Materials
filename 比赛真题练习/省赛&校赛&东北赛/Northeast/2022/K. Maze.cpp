#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int T,n,m;
int dis[maxn][maxn][maxn][4];//(i,j)this direction for k steps,direction is o.
int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool mapp[maxn][maxn],book[maxn][maxn][maxn][4];
void init()
{
	memset(mapp,0,sizeof mapp);
	memset(book,0,sizeof book);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char ch=getchar();
			while(ch!='.'&&ch!='*')
				ch=getchar();
			if(ch=='*')
				mapp[i][j]=1;
		}
	}
}
struct node{
	int x,y,co,d,dist;
	node(int _x,int _y,int _co,int _d,int _dist){
		x=_x,y=_y,co=_co,d=_d,dist=_dist;
	}
};
queue<node> q;
void bfs()
{
	memset(dis,0x7f,sizeof dis);
	dis[1][1][0][0]=dis[1][1][0][1]=dis[1][1][0][2]=dis[1][1][0][3]=0;
	book[1][1][0][0]=book[1][1][0][1]=book[1][1][0][2]=book[1][1][0][3]=1;
	q.push(node(1,1,0,0,0)),q.push(node(1,1,0,1,0)),q.push(node(1,1,0,2,0)),q.push(node(1,1,0,3,0));
	while(q.size()){
		node u=q.front();
		q.pop();
		int x=u.x,y=u.y,co=u.co,d=u.d,dist=u.dist;
		for(int i=0;i<=3;i++){
			int nx=x+step[i][0],ny=y+step[i][1];
			if(!mapp[nx][ny]&&nx&&ny&&nx<=n&&ny<=n){
				if(!book[nx][ny][1][i]&&d!=i){
					book[nx][ny][1][i]=1;
					q.push(node(nx,ny,1,i,dist+1));
					dis[nx][ny][1][i]=dist+1;
				}
				if(!book[nx][ny][co+1][d]&&co+1<=m&&i==d){
					book[nx][ny][co+1][d]=1;
					q.push(node(nx,ny,co+1,d,dist+1));
					dis[nx][ny][co+1][d]=dist+1;
				}
			}
		}
	}
}
void output()
{
	int ans=0x7f7f7f7f;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=3;j++)
			ans=min(ans,dis[n][n][i][j]);
	printf("%d\n",ans==0x7f7f7f7f?-1:ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		bfs();
		output();
	}
	return 0;
}