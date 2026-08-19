#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,last,k;
long long ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],up[maxn][20],p[maxn],book[maxn],fa[maxn],deep[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
void dfs(int u,int f)
{
	up[u][0]=f;
	for(int i=1;i<=19;i++)
		up[u][i]=up[up[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])swap(u,v);
	int delta=deep[u]-deep[v];
	for(int i=0;i<=19;i++)
		if(delta&(1<<i))
			u=up[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(up[u][i]!=up[v][i])
			u=up[u][i],v=up[v][i];
	return up[u][0];
}
void jump(int u,int goal)
{
	goal=find(goal);
	while(find(u)!=goal)
		u=fa[u],fa[u]=goal,u=up[u][0];
	book[goal]=1;	
}
int main(){
	scanf("%d%d%d",&n,&m,&last);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	dfs(last,last);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=m;i++)
	{
		if(book[find(p[i])])continue;
		int t=lca(last,p[i]);
		ans+=(1ll*deep[last]+deep[p[i]]-2*deep[t]);
		jump(last,t);
		jump(p[i],t);
		last=p[i];
	}
	printf("%lld",ans);
	return 0;
}
