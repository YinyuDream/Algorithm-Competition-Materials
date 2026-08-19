#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,num;
struct Edge{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int size[maxn],fa[maxn],son[maxn],deep[maxn],news[maxn],old[maxn],top[maxn];
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
struct node{
	int l,r,len,sum,lazy;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r)
	return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
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
	//printf("%d     %d\n",tree[id].l,tree[id].r);
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
void trim(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			swap(x,y);
		}
		update(1,news[top[x]],news[x],1);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
	swap(x,y);
	if(news[x]<news[y])
	update(1,news[x]+1,news[y],1);
}
int find(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			swap(x,y);
		}
		ans+=query(1,news[top[x]],news[x]);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
	swap(x,y);
	if(news[x]<news[y])
	ans+=query(1,news[x]+1,news[y]);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char opt;
		int a,b;
		scanf("\n%c %d%d",&opt,&a,&b);
		if(opt=='P')
		{
			trim(a,b);
		}
		else
		{
			printf("%d\n",find(a,b));
		}
	}
	return 0;
}