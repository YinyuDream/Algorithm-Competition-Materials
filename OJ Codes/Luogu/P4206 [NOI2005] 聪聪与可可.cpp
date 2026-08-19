#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m,c,s,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],deg[maxn];
double p[maxn][maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int dis[maxn][maxn];//可可在s，聪聪在c，聪聪的下一个地址 
void dijkstra(int s)
{
	
}
double dfs(int u,int v)
{
	if(p[u][v])return p[u][v];
	
}
int main(){
	scanf("%d%d%d%d",&n,&m,&c,&s);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		deg[u]++;
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dijstra(i); 
	return 0;
}
