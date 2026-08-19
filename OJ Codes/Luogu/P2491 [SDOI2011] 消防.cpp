#include<cstdio>
using namespace std;
int n,s,st,ed;
struct node{
	int to,next,len;
}edge[maxn];
int head[maxn],dis[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].len=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			dis[v]=dis[u]+edge[i].len;
			dfs(v,u);
		}
	}
}
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		if(dis[st]<dis[i])
			st=i;
	memset(dis,0,sizeof dis);
	dfs(st,st);
	for(int i=1;i<=n;i++)
		if(dis[ed]<dis[i])
	return 0;
}
