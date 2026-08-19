#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,m;
int fa[maxn][20],deep[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int x,int f)
{
	for(int i=1;(1<<i)<=deep[x];i++)
	fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			deep[v]=deep[x]+1;
			fa[v][0]=x;
			dfs(v,x);
		}
	}
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])
	swap(u,v);
	int t=deep[u]-deep[v];
	for(int i=0;(1<<i)<=t;i++)
		if(t&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int x,int y)
{
	return deep[x]+deep[y]-2*deep[lca(x,y)];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int t1=lca(a,b),t2=lca(c,d);
		if(dis(a,b)==dis(a,t2)+dis(t2,b)||dis(c,d)==dis(c,t1)+dis(d,t1))
		puts("Y");
		else
		puts("N");
	}
	return 0;
}
