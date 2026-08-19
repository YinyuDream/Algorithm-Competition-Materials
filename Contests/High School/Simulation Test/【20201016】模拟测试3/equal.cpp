#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,k;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
int size[maxn],deep[maxn],fa[maxn][20];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=1;
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v][0]=u;
			deep[v]=deep[u]+1;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])swap(u,v);
	int delta=deep[u]-deep[v];
	for(int i=0;i<=19;i++)
		if(delta&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]==fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int calc(int u,int v)
{
	int delta=deep[u]-deep[v]-1;
	for(int i=0;i<=19;i++)
		if(delta&(1<<i))
			u=fa[u][i];
	return u;
}
int find(int u,int delta)
{
	for(int i=0;i<=19;i++)
		if(delta&(1<<i))
			u=fa[u][i];
	return size[fa[u][0]]-size[u];
}
int main(){
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,1);
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		if(u==v){
			printf("%d\n",n);
			continue ;
		}
		int t=lca(u,v);
		if(deep[u]==deep[v])printf("%d\n",n-size[calc(u,t)]-size[calc(v,t)]);
		else{
			 int dis=deep[u]+deep[v]-2*deep[t];
			 if(dis&1){
			 	puts("0");
			 	continue ;
			 }
			 if(deep[u]<deep[v])swap(u,v);
			 printf("%d\n",find(u,dis/2-1));
		}
	}
	return 0;
}
