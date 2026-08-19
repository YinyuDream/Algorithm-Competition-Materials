#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,root;
int a[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int fa[maxn][20],top[maxn],size[maxn],son[maxn],deep[maxn],tid[maxn],old[maxn],cnt;
void dfs1(int u,int f)
{
	size[u]=1;
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v][0]=u;
			deep[v]=deep[u]+1;
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
	tid[u]=++cnt;
	old[cnt]=u;
	if(!son[u])return ;
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u][0]){
			dfs2(v,v);
		}
	}
}
struct segment_tree{
	int l,r,minx,lazy;
}tree[maxn*4];
void pushdown(int id)
{
	tree[id*2].minx=tree[id*2+1].minx=tree[id*2].lazy=tree[id*2+1].lazy=tree[id].lazy;
	tree[id].lazy=0;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].minx=a[old[l]];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx);
}
void update(int id,int l,int r,int c)
{
	if(l>r)return ;
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].minx=tree[id].lazy=c;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx);
}
int query(int id,int l,int r)
{
	if(l>r)return 0x7f7f7f7f;
	if(tree[id].l==l&&tree[id].r==r)return tree[id].minx;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return min(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
void trim(int u,int v,int w)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		update(1,tid[top[u]],tid[u],w);
		u=fa[top[u]][0];
	}
	if(deep[u]>deep[v])swap(u,v);
	update(1,tid[u],tid[v],w);
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;(1<<i)<=h;i++)
		if((1<<i)&h)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int calc(int u,int v)
{
	int delta=deep[v]-deep[u]-1;
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			v=fa[v][i];
	return v;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs1(1,1),dfs2(1,1);
	scanf("%d",&root);
	build(1,1,n);
	
	for(int i=1,opt,u,v,w;i<=m;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&root);
		}else if(opt==2){
			scanf("%d%d%d",&u,&v,&w);
			trim(u,v,w);
		}else{
			scanf("%d",&u);
			int t=lca(u,root);
			if(u==root)printf("%d\n",query(1,1,n));
			else if(t!=u||root==1)printf("%d\n",query(1,tid[u],tid[u]+size[u]-1));
			else{
				v=calc(u,root);
				printf("%d\n",min(query(1,1,tid[v]-1),query(1,tid[v]+size[v],n)));
			}
		}
	}
	return 0;
}
