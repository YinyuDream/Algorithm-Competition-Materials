#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm> 
using namespace std;
const int maxn=1e6+10;
int n,k,num,q;
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
int fa[maxn],son[maxn],deep[maxn],size[maxn],top[maxn],news[maxn],old[maxn];
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
			if(size[son[u]]<size[v]||son[u]==0)
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
//区间覆盖为0或1，并查询【L，r】 0或1的个数
struct node{
	int l,r,len,lazy,sum;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r,tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r){
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id].lazy;
	tree[id*2].sum=tree[id*2].len*((tree[id].lazy+1)/2);
	tree[id*2+1].lazy=tree[id].lazy;
	tree[id*2+1].sum=tree[id*2+1].len*((tree[id].lazy+1)/2);
	tree[id].lazy=0;
}
void update(int id,int l,int r,int opt)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].lazy=opt==1?1:-1;
		tree[id].sum=opt==1?tree[id].len:0;
		return ;
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	update(id*2,l,r,opt);
	else if(l>mid)
	update(id*2+1,l,r,opt);
	else
	update(id*2,l,mid,opt),update(id*2+1,mid+1,r,opt);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum; 
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r){
		return tree[id].sum;	
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)>>1;
	if(r<=mid)
	return query(id*2,l,r);
	else if(l>mid)
	return query(id*2+1,l,r);
	else
	return query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
void trim(int u,int v)
{
	
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
		update(1,news[top[u]],news[u],1);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v]){
		swap(u,v);
	}
	update(1,news[u],news[v],1);
}
int find(int u,int v)
{
	int t=v;
	int ans=0;
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
		ans+=query(1,news[top[u]],news[u]);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v]){
		swap(u,v);
	}
	ans+=query(1,news[u],news[v]);
	return deep[t]-ans+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int v;
		scanf("%d",&v);
		add(v,i);
	}
	dfs1(0,0),dfs2(0,0),build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		string opt;
		int x,y;
		cin>>opt;
		if(opt=="install")
		{
			scanf("%d",&x);
			printf("%d\n",find(0,x));
			trim(0,x);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(1,news[x],news[x]+size[x]-1));
			update(1,news[x],news[x]+size[x]-1,0);
		}
	}
	return 0;
}
