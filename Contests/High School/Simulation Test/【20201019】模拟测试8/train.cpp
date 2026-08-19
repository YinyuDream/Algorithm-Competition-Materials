#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,last,k,ans;
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
void jump(int u,int v,int depth)
{
	while(deep[u]>=depth||deep[v]>=depth)
	{
		if(deep[u]<deep[v])swap(u,v);
		book[u]=1;
		if(u==v)break;
		//printf("ss%d\n",u);
		int t=u;
		find(fa[u]);
		u=up[fa[u]][0];
		if(deep[u]>=depth)
		merge(t,up[fa[t]][0]);
	}
}
int main(){
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
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
		if(book[p[i]])continue;
		int t=lca(last,p[i]);
		ans+=(deep[last]+deep[p[i]]-2*deep[t]);
		jump(last,p[i],deep[t]);
		last=p[i];
		//printf("%d\n",ans);
	}
	printf("%d",ans);
	return 0;
}
