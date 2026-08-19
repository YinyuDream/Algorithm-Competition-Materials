#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n,m,k,smax,ans=0x7f7f7f7f;
int dis[maxn],sr[maxn];
short book[maxn];
bool Book[maxn];
struct node{
	int to,next,weight;
}edge[maxn<<1];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].weight=w;
	head[u]=k;
}
struct node2{
	int wt,id;
	node2(int wt1,int id1){
		wt=wt1,id=id1;
	}
	friend bool operator<(node2 a,node2 b){
		return a.wt>b.wt;
	}
};
priority_queue<node2>q;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),add(u,v,w),add(v,u,w);
}
void dijkstra()
{
	int s=0,tmp=0;
	memset(dis,0x3f,sizeof dis);
	dis[n]=0;
	q.push(node2(0,n));
	while((++s)<n)
	{
		while(book[q.top().id])q.pop();
		tmp=q.top().id,q.pop(),book[tmp]=1;
		for(int i=head[tmp];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>dis[tmp]+edge[i].weight)
			{
				dis[v]=dis[tmp]+edge[i].weight;
				q.push(node2(dis[v],v));
			}
		}
	}
}
void dfs(int x,int step,int &t)
{
	if(step+dis[x]>=t)return ;
	if(x==n&&step>dis[1]&&step<ans){
		ans=step;return ;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]<2)
			book[v]++;
			dfs(v,step+edge[i].weight,t);
			book[v]--;
	}
}
void Dfs(int x,int step,int Minx,int &tt)
{
	if((step>=dis[1]&&x!=n)||(step>dis[1]&&x==n))return ;	//printf("%d %d\n",Minx,x);
	if(x==n){
		tt=Minx;return ;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(Book[v]==0)Book[v]=1,Dfs(v,step+edge[i].weight,min(Minx,edge[i].weight),tt),Book[v]=0;
	}
}
void Astar()
{
	int Minn=0x7f7f7f7f;
	Book[1]=1;
	Dfs(1,0,0x7f7f7f7f,Minn);
	smax=dis[1]+2*Minn+1;
	memset(book,0,sizeof book);
	book[1]=1;
	dfs(1,0,smax);
	printf("%d",ans);
}
int main(){
	init();
	dijkstra();
	Astar();
	return 0;
}
