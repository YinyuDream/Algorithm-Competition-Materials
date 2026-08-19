#include<cstdio>
using namespace std;
int n,m,k;
int t[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
struct player{
	int st,ed,lca;
}q[maxn];
int fa[maxn][20],deep[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=1;i<=20;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			dfs(v,u);
		}
	}
}
void lca(int u,int v)
{
	if(deep[u]<deep[v])
	swap(u,v);
	int t=deep[u]-deep[v];
	for(int i=0;i<=19;i++)
		if(t&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v)
{
	return deep[u]+deep[v]-2*deep[lca(u,v)];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
	scanf("%d",&t[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		q[i].st=u;
		q[i].ed=v;
		q[i].lca=Lca(u,v);
	}
	
	return 0;
}
