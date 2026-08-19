#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int deep[maxn],fa[maxn][20],cf[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			dfs(v,u);
		}
	}
}
int get(int u,int f)
{
	int t=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)t+=get(v,u),cf[u]+=cf[v];
	}
	return t+(cf[u]!=0);
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])
	swap(u,v);
	int t=deep[u]-deep[v];
	for(int i=0;i<=19;i++)
		if((1<<i)&t)
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main(){
	freopen("treecnt.in","r",stdin);
	freopen("treecnt.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			memset(cf,0,sizeof cf);
			for(int k=i;k<j;k++)
			cf[k]++,cf[k+1]++,cf[lca(k,k+1)]-=2;
			ans+=get(1,1);
		}
	printf("%d",ans);
	return 0;
}
