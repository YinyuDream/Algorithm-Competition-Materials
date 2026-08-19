#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,root,in,k;
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
int size[maxn],fa[maxn],top[maxn],deep[maxn],son[maxn],dfn[maxn],old[maxn],cnt;
void dfs1(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v]=u;
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
	dfn[u]=++cnt;
	old[cnt]=u;
	if(!son[u])return ;
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa[u]&&v!=son[u])
			dfs2(v,v);
	}
}
struct segment_tree{
	int l,r,sum,lazy;
}tree[maxn*4];
void pushdown(int id)
{
	tree[id*2].sum+=(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy;
	tree[id*2+1].sum+=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy;
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id].lazy=0; 
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].sum=a[old[l]];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void update(int id,int l,int r,int c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].sum+=(tree[id].r-tree[id].l+1)*c;
		tree[id].lazy+=c;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
int lca(int u,int v)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])
	swap(u,v);
	return u;
}
void trim(int u,int v,int w)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		update(1,dfn[top[u]],dfn[u],w);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])
	swap(u,v);
	update(1,dfn[u],dfn[v],w);
}
int find(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		ans+=query(1,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])
	swap(u,v);
	ans+=query(1,dfn[u],dfn[v]);
	return ans;
}
int main(){
	freopen("re.in","r",stdin);
	freopen("re.out","w",stdout);
	scanf("%d%d%d",&n,&root,&q);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs1(root,root),dfs2(root,root),build(1,1,n);
	for(int i=1,opt,u,v,w;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&u,&v,&w);
			if(!in||lca(u,v)!=root){
				trim(u,v,w); 
			}else{
				if((deep[u]>deep[v])||(deep[u]==deep[v]&&u>v))
				swap(u,v);
				trim(u,root,w);
			}
		}else if(opt==2){
			scanf("%d%d%d",&u,&v,&w);
			trim(u,v,-w);
		}else if(opt==3){
			in^=1;
		}else{
			scanf("%d%d",&u,&v);
			printf("%d\n",find(u,v));
		}
	}
}
