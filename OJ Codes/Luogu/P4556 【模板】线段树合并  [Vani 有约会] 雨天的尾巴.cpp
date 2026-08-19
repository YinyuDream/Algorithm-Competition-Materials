#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=4e6+10,inf=0x3f3f3f3f;
int n,m,k,cnt;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],fa[maxn][20],deep[maxn],root[maxn],ans[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
struct segment_tree{
	int lson,rson,mx,mxp;
}tree[maxn*4];
void dfs(int u,int f)
{
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v][0]=u;
			deep[v]=deep[u]+1;
			dfs(v,u);
		}
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;i<=19;i++)
		if((1<<i)&h)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int build(int l,int r)
{
	tree[++cnt].mx=-inf,tree[cnt].mxp=l;
	return cnt;
}
void update(int id,int l,int r,int pos,int val)
{
	if(l==r){
		tree[id].mxp=pos;
		if(tree[id].mx==-inf)tree[id].mx=val;
		else tree[id].mx+=val;
		return ;
	}
	int mid=(l+r)/2;
	if(!tree[id].lson)tree[id].lson=build(l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,r);
	if(pos<=mid)update(tree[id].lson,l,mid,pos,val);
	else update(tree[id].rson,mid+1,r,pos,val);
	tree[id].mx=max(tree[tree[id].lson].mx,tree[tree[id].rson].mx);
	if(tree[tree[id].lson].mx>=tree[tree[id].rson].mx)tree[id].mxp=tree[tree[id].lson].mxp;
	else tree[id].mxp=tree[tree[id].rson].mxp;
}
int merge(int u,int v,int l,int r)
{
	if(!u||!v)return u+v;
	if(l==r){
		if(tree[v].mx!=-inf&&tree[u].mx!=-inf)
		tree[u].mx+=tree[v].mx;
		else if(tree[u].mx==-inf&&tree[v].mx!=-inf)
		tree[u].mx=tree[v].mx;
		return u;
	}
	int mid=(l+r)/2;
	tree[u].lson=merge(tree[u].lson,tree[v].lson,l,mid);
	tree[u].rson=merge(tree[u].rson,tree[v].rson,mid+1,r);
	tree[u].mx=max(tree[tree[u].lson].mx,tree[tree[u].rson].mx);
	if(tree[tree[u].lson].mx>=tree[tree[u].rson].mx)tree[u].mxp=tree[tree[u].lson].mxp;
	else tree[u].mxp=tree[tree[u].rson].mxp;
	return u;
}
void dfs2(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs2(v,u);
			root[u]=merge(root[u],root[v],1,n);
		}
	}
	ans[u]=tree[root[u]].mxp;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	root[0]=build(1,n);
	for(int i=1;i<=n;i++)
		root[i]=build(1,n);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		update(root[u],1,n,w,1);
		update(root[v],1,n,w,1);
		update(root[lca(u,v)],1,n,w,-1);
		update(root[fa[lca(u,v)][0]],1,n,w,-1);
	}
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		printf("%d\n",tree[root[i]].mx!=-0x3f3f3f3f&&tree[root[i]].mx!=0?ans[i]:0);
	return 0;
}
