#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int fa[maxn][20],deep[maxn],cf[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
void dfs(int x,int f)
{
	for(int i=1;(1<<i)<=deep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		
		if(edge[i].to!=f)
		{
			fa[edge[i].to][0]=x;
			deep[edge[i].to]=deep[x]+1;
			dfs(edge[i].to,x);
		}
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;(1<<i)<=h;i++)
		if((1<<i)&h)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int getans(int u,int f)
{
	int ans=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			ans=max(getans(v,u),ans);
			cf[u]+=cf[v];
		}
	}
	return max(ans,cf[u]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,1);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),cf[u]++,cf[v]++,cf[lca(u,v)]--,cf[fa[lca(u,v)][0]]--;
	printf("%d",getans(1,1));
	return 0;
}
