#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans=0x7f7f7f7f;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int fa[maxn][20],deep[maxn],sum[maxn],num[maxn];
int mx[maxn],lmx[maxn];
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
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			dfs(v,u);
		}
	}
}
void get_sum(int u,int f)
{
	int tot=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			get_sum(v,u);
			sum[u]+=sum[v];
			if(sum[v]>=mx[u])lmx[u]=mx[u],mx[u]=sum[v];
			else if(sum[v]>lmx[u])lmx[u]=sum[v];
			tot+=sum[v];
		}
	}
	num[1]+=tot-mx[u];
}
void dp(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			int t=mx[v],tp=lmx[v];
			num[v]=num[u]+mx[v]-max(t,sum[v])+mx[u]-(mx[u]==sum[v]?lmx[u]:mx[u]);
			if(sum[v]>=mx[v])lmx[v]=mx[v],mx[v]=sum[v];
			else if(sum[v]>lmx[v])lmx[v]=sum[v];
			dp(v,u);
			mx[v]=t,lmx[v]=tp;
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
int main(){
	freopen("pl.in","r",stdin);
	freopen("pl.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		sum[u]++;
		sum[v]++;
		sum[lca(u,v)]-=2;
	}
	get_sum(1,1);
	dp(1,1);
	for(int i=1;i<=n;i++)
		ans=min(ans,num[i]);
	printf("%d",ans);
	return 0;
}
