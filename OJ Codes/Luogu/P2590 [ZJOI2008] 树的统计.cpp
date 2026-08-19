#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,k,num;
int head[maxn];
struct Edge{
	int to,next;
}edge[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int fa[maxn],son[maxn],deep[maxn],size[maxn],news[maxn],old[maxn],top[maxn],a[maxn];
void dfs1(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			fa[v]=u;
			deep[v]=deep[u]+1;
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
		if(v!=fa[u]&&v!=son[u])
		{
			dfs2(v,v);
		}
	}
}
struct node{
	int l,r,len;
	int maxm,sum,lazy;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r,tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r)
	{
		tree[id].sum=tree[id].maxm=a[old[l]];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].maxm=max(tree[id*2].maxm,tree[id*2+1].maxm);
}
void pushdown(int id)
{
	tree[id*2].sum+=tree[id*2].len*tree[id].lazy;
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2].maxm+=tree[id].lazy;
	tree[id*2+1].sum+=tree[id*2+1].len*tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2+1].maxm+=tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int val)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].sum+=tree[id].len*val;
		tree[id].lazy+=val;
		tree[id].maxm+=val;
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
	tree[id].maxm=max(tree[id*2].maxm,tree[id*2+1].maxm);
}
int query(int id,int l,int r,int opt)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		if(opt==1)
		{
			return tree[id].sum;
		}
		else
		{
			return tree[id].maxm;
		}
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	{
		if(opt==1)
		{
			return query(id*2,l,r,1);	
		}
		else
		{
			return query(id*2,l,r,2);
		}
	}
	else if(l>mid)
	{
		if(opt==1)
		{
			return query(id*2+1,l,r,1);	
		}
		else
		{
			return query(id*2+1,l,r,2);
		}
	}
	else
	{
		if(opt==1)
		{
			return query(id*2,l,mid,1)+query(id*2+1,mid+1,r,1);
		}
		else
		{
			return max(query(id*2,l,mid,2),query(id*2+1,mid+1,r,2));
		}
	}
}
int find(int x,int y,int opt)
{
	int ans=opt==1?0:-0x7f7f7f7f;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			swap(x,y);
		}
		if(opt==1)
		{
			ans+=query(1,news[top[x]],news[x],opt);
		}
		else
		{
			ans=max(ans,query(1,news[top[x]],news[x],opt));
		}
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
	{
		swap(x,y);
	}
	if(opt==1)
	{
		ans+=query(1,news[x],news[y],1);
	}
	else
	{
		ans=max(ans,query(1,news[x],news[y],2));
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&q);
	dfs1(1,1),dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		string opt;
		int u,b;
		cin>>opt;
		scanf(" %d%d",&u,&b);
		if(opt=="QMAX")
		{
			printf("%d\n",find(u,b,2));
		}
		else if(opt=="QSUM")
		{
			printf("%d\n",find(u,b,1));
		}
		else//CHANGE
		{
			int t=b-a[u];
			a[u]=b;
			update(1,news[u],news[u],t);
		}
	}
	return 0;
}
