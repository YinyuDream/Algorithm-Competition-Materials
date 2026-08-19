#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,num;
int color[maxn];
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
int fa[maxn],son[maxn],top[maxn],deep[maxn],size[maxn],old[maxn],news[maxn];
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
			son[u]=v;	
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
		dfs2(v,v);
	}
}
struct node{
	int l,r,lcolor,rcolor,cnt,lazy;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r)
	{
		tree[id].lcolor=tree[id].rcolor=color[old[l]];
		tree[id].cnt=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].lcolor=tree[id*2].lcolor;
	tree[id].rcolor=tree[id*2+1].rcolor;
	if(tree[id*2].rcolor!=tree[id*2+1].lcolor)
	tree[id].cnt=tree[id*2].cnt+tree[id*2+1].cnt;
	else
	tree[id].cnt=tree[id*2].cnt+tree[id*2+1].cnt-1;
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id].lazy;
	tree[id*2].lcolor=tree[id*2].rcolor=tree[id].lazy;
	tree[id*2].cnt=1;
	tree[id*2+1].lazy=tree[id].lazy;
	tree[id*2+1].lcolor=tree[id*2+1].rcolor=tree[id].lazy;
	tree[id*2+1].cnt=1;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int val)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].lazy=tree[id].lcolor=tree[id].rcolor=val;
		tree[id].cnt=1;
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
	tree[id].lcolor=tree[id*2].lcolor,tree[id].rcolor=tree[id*2+1].rcolor;
	tree[id].cnt=tree[id*2].cnt+tree[id*2+1].cnt-(tree[id*2].rcolor==tree[id*2+1].lcolor); 
}
node query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		return tree[id];
	}
	if(tree[id].lazy)
	pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	return query(id*2,l,r);
	else if(l>mid)
	return query(id*2+1,l,r);
	else
	{
		node lson=query(id*2,l,mid),rson=query(id*2+1,mid+1,r),ans;
		ans.lcolor=lson.lcolor;
		ans.rcolor=rson.rcolor;
		ans.cnt=lson.cnt+rson.cnt-(lson.rcolor==rson.lcolor);
		return ans;
	}
}
void trim(int x,int y,int val)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		swap(x,y);
		update(1,news[top[x]],news[x],val);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
	swap(x,y);
	update(1,news[x],news[y],val);
}
int find(int x,int y)
{
	
	int ans=0;
	node line1,line2;//左右两个链的上一个区间的信息
	line1.lcolor=line2.lcolor=0;//初始化！！！ 
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			node tmp=query(1,news[top[y]],news[y]);
			ans+=tmp.cnt-(line1.lcolor==tmp.rcolor);
			line1=tmp;
			y=fa[top[y]]; 
		}
		else
		{
			node tmp=query(1,news[top[x]],news[x]);
			ans+=tmp.cnt-(line2.lcolor==tmp.rcolor);
			line2=tmp;
			x=fa[top[x]];
		}
	}//puts("weg");
	if(deep[x]<deep[y])
	{
		node tmp=query(1,news[x],news[y]);
		ans+=tmp.cnt-(tmp.lcolor==line2.lcolor)-(tmp.rcolor==line1.lcolor);
	}
	else
	{
		node tmp=query(1,news[y],news[x]);
		ans+=tmp.cnt-(tmp.lcolor==line1.lcolor)-(tmp.rcolor==line2.lcolor);
	}
	return ans;
}
int main()
{
	//node weg;
	//printf("%d\n",weg.lcolor);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	scanf("%d",&color[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,1),dfs2(1,1),build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char opt;
		scanf("\n%c",&opt);
		if(opt=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			trim(a,b,c);
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",find(a,b));
		}
	}
	return 0;
}