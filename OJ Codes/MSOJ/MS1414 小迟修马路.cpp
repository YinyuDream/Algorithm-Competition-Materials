#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,s,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int deep[maxn],dis[maxn],fa[maxn][20],mx[maxn][20];
void dfs(int u,int f)
{
	for(int i=1;i<=19;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
		mx[u][i]=max(mx[u][i-1],mx[fa[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			dis[v]=dis[u]+edge[i].wt;
			mx[v][0]=dis[v];
			fa[v][0]=u;
			dfs(v,u);
		}
	}
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])swap(u,v);
	int delta=deep[u]-deep[v];
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int calc(int u,int goal)
{
	int delta=deep[u]-deep[goal],val=-0x7f7f7f7f;
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			val=max(val,mx[u][i]),
			u=fa[u][i];
	return val-dis[goal];
}
int main(){
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(s,s);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		int t=lca(u,v),val=max(calc(u,t),calc(v,t));
		printf("%d\n",dis[u]+dis[v]-2*dis[t]-(val>0?val:0));
	}
	return 0;
}
