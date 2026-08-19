#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
	int to,next,weight;
}edge[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int fa[maxn],son[maxn],deep[maxn],size[maxn],news[maxn],old[maxn],top[maxn],pos[maxn],a[maxn],pos_rev[maxn];
void dfs1(int u,int f,int p)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			fa[v]=u;
			deep[v]=deep[u]+1;
			pos[i/2]=v;
			dfs1(v,u,i);
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
		if(v!=fa[u]&&v!=son[u])
		{
			dfs2(v,v);
		}
	}
}
struct node{
	int l,r,len;
	int lazy,sum,max_val,min_val;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l;
	tree[id].r=r;
	tree[id].len=r-l+1;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].max_val=tree[id].min_val=tree[id].sum=a[pos_rev[l]];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		add(u,v,w);
		add(v,u,w);
		a[i]=w;
	}
	dfs1(1,1,-1);
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		string opt;
		int u,v;
		cin>>opt;
		if(opt=="C")
		{
			
		}
		else if(opt=="N")
		{
			
		}
		else if(opt=="SUM")
		{
			
		}
		else if(opt=="MAX")
		{
			
		}
		else
		{
			
		}
	}
	return 0;
}
