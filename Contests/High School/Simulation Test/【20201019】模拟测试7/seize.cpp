#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,k,cnt,ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],t[maxn];
int w[maxn],son[maxn],size[maxn],fa[maxn],top[maxn],sum[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v]=u;
			sum[v]=sum[u]+w[v];
			dfs(v,u);
			if(size[son[u]]<size[v])
			son[u]=v;
		}
	}
	size[u]=size[son[u]]+w[u];
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	if(!son[u])return ;
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa[u]&&v!=son[u]){
			dfs2(v,v);
		}
	}
}
void dfs3(int u)
{
	int size=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa[u]){
			dfs3(v);
			size++;
		}
	}
	if(!size)t[++cnt]=sum[u]-sum[top[u]]+w[top[u]];
}
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	dfs(1,1),dfs2(1,1),dfs3(1);
	sort(t+1,t+cnt+1,cmp);
	for(int i=1;i<=min(m,cnt);i++)
		ans+=t[i];
	printf("%lld",ans);
	return 0;
}
