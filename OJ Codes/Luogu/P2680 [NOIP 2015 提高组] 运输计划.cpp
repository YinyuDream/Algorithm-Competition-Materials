#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,l,r,max_val;
struct node{
	int to,next,wt;
}edge[maxn];
struct query{
	int a,b,l,Lca;
}q[maxn];
int head[maxn];
int fa[maxn][20],dis[maxn],deep[maxn],e[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=1;i<=19;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dis[v]=dis[u]+edge[i].wt;
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			e[v]=i;
			dfs(v,u);
		}
	}
}
int lca(int u,int v)
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
int _dis(int u,int v)
{
	return dis[u]+dis[v]-2*dis[lca(u,v)]; 
}
int sum[maxn],cf[maxn];
void dfs2(int x,int f)
{
	sum[x]=cf[x];
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f)
			dfs2(v,x),
			sum[x]+=sum[v];
	}
}
bool check(int x)
{
	int cnt=0;
	memset(cf,0,sizeof cf);
	memset(sum,0,sizeof sum);
	for(int i=1;i<=m;i++)
		if(q[i].l>x)
			cf[q[i].a]++,
			cf[q[i].b]++,
			cf[q[i].Lca]-=2,
			cnt++;
	dfs2(1,1);
	for(int i=1;i<n;i++)
		if(sum[i]==cnt&&max_val-edge[e[i]].wt<=x)
			return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		r=max(r,_dis(u,v));
		q[i]={u,v,_dis(u,v),lca(u,v)};
		
	}
	max_val=r;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
