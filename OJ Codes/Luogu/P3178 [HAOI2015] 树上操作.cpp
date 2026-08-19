#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,k,num;
struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],top[maxn],son[maxn],deep[maxn],fa[maxn],news[maxn],old[maxn],a[maxn],size[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
struct node{
	int l,r,len,sum,lazy;
}tree[maxn];
void dfs1(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			deep[v]=deep[u]+1;
			fa[v]=u;
			dfs1(v,u);
			size[u]+=size[v];
			if(size[son[u]]<size[v])
			{
				son[u]=v;
			}
		}
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	news[u]=++num;
	old[num]=u;
	if(son[u])
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u])
		{
			dfs2(v,v);
		}
	}
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r)
	{
		tree[id].sum=a[old[l]];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void pushdown(int id)
{
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2].sum+=tree[id*2].len*tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2+1].sum+=tree[id*2+1].len*tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int val)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].sum+=tree[id].len*val;
		tree[id].lazy+=val;
		return ;
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	update(id*2,l,r,val);
	else if(l>mid)
	update(id*2+1,l,r,val);
	else
	update(id*2,l,mid,val),update(id*2+1,mid+1,r,val);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		return tree[id].sum;
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	return query(id*2,l,r);
	else if(l>mid)
	return query(id*2+1,l,r);
	else
	return query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
int find(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
		ans+=query(1,news[top[u]],news[u]);
		u=fa[top[u]];
	}
	if(deep[u]<deep[v]){
		swap(u,v);
	}
	ans+=query(1,news[v],news[u]);
	return ans;
}
main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,a,x;
		scanf("%lld",&opt);
		if(opt==1)
		{
			scanf("%lld%lld",&x,&a);
			update(1,news[x],news[x],a);
		}
		else if(opt==2)
		{
			scanf("%lld%lld",&x,&a);
			update(1,news[x],news[x]+size[x]-1,a);
		}
		else
		{
			scanf("%lld",&x);
			printf("%lld\n",find(1,x));
		}
	}
	return 0;
}
