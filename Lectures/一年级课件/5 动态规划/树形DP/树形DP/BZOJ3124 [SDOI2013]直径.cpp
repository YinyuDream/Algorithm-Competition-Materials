#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long long maxn=400005;
struct node
{
	long long to,next,dis;
} edge[maxn<<1];
long long n,head[maxn],k=0,root,s1[maxn],s2[maxn],top1=0,top2=0,mx[maxn],size[maxn],broot=0,deep[maxn],fa[maxn][25];
long long ans=0,dist[maxn],diss[maxn],maxdis=0;
void add(long long u,long long v,long long w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].dis=w;
	head[u]=k;
}
void dfs(long long x,long long fa)
{
	for(long long i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		dist[edge[i].to]=dist[x]+edge[i].dis;
		if(dist[edge[i].to]>=dist[root]) root=edge[i].to;
		dfs(edge[i].to,x);
	}
}
void get_root(long long x,long long fa)
{
	size[x]=1;
	for(long long i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		get_root(edge[i].to,x);
		size[x]+=size[edge[i].to];
		mx[x]=max(mx[x],size[edge[i].to]);
	}
	mx[x]=max(mx[x],n-size[x]);
	if(mx[x]<mx[broot]) broot=x;
}
long long lca(long long x,long long y)
{
	if(deep[x]<deep[y]) swap(x,y);
	long long k=deep[x]-deep[y];
	for(long long i=0;(1<<i)<=k;i++) if(k&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	k=log2(deep[x]+1.0);
	for(long long i=k;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void _dfs(long long x,long long father)
{
	for(long long i=1;(1<<i)<=deep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(long long i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==father) continue;
		deep[edge[i].to]=deep[x]+1;
		fa[edge[i].to][0]=x;
		_dfs(edge[i].to,x);
	}
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1,a,b,c;i<n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	/*part 1:***********************************************/ //求直径以及距离相等的点(直径)
	memset(dist,0,sizeof(dist));
	dfs(1,1);
	memset(dist,0,sizeof(dist));
	dfs(root,root);
	for(long long i=1;i<=n;i++) diss[i]=dist[i];
	memset(dist,0,sizeof(dist));
	dfs(root,root);maxdis=dist[root];
	printf("%lld\n",maxdis);
	for(long long i=1;i<=n;i++)
	{
		if(diss[i]==maxdis&&dist[i]==maxdis) return printf("0\n"),0;//菊花图
		if(diss[i]==maxdis) s1[++top1]=i;//一边的点
		if(dist[i]==maxdis) s2[++top2]=i;//另一边的点
	}
	/*part 2:***********************************************/ //直径必过重心，求重心，并预处理lca
	broot=0;mx[0]=1e12;
	get_root(1,1);
	_dfs(broot,broot);
	/*part 3:***********************************************/ //求出两端lca的距离即为答案
	long long fa1,fa2;
	if(top1==1) fa1=s1[top1];
	else
	{
		fa1=lca(s1[1],s1[2]);
		for(long long i=3;i<=top1;i++) fa1=lca(fa1,s1[i]);
	}
	if(top2==1) fa2=s2[top2];
	else
	{
		fa2=lca(s2[1],s2[2]);
		for(long long i=3;i<=top2;i++) fa2=lca(fa2,s2[i]);
	}
	printf("%lld\n",deep[fa1]+deep[fa2]-(deep[lca(fa1,fa2)]<<1));
	return 0;
}
