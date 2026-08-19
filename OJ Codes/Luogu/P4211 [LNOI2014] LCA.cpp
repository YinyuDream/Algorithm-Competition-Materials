#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,p=201314;
int n,m,k;
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
int deep[maxn],fa[maxn],size[maxn],top[maxn],tid[maxn],old[maxn],son[maxn],cnt;
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
	tid[u]=++cnt;
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
	if(tree[id].l==tree[id].r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void update(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].sum+=tree[id].r-tree[id].l+1;
		tree[id].lazy++;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r);
	else if(l>mid)update(id*2+1,l,r);
	else update(id*2,l,mid),update(id*2+1,mid+1,r);
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
void trim(int u,int v)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		update(1,tid[top[u]],tid[u]);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	update(1,tid[u],tid[v]);
}
int find(int u,int v)
{
	int num=0;
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		num+=query(1,tid[top[u]],tid[u]);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	num+=query(1,tid[u],tid[v]);
	return num;
}
int ans[maxn];
struct _query{
	int p,z,id,flag;
}q[maxn];
bool cmp(_query a,_query b)
{
	return a.p<b.p;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2,v;i<=n;i++){
		scanf("%d",&v);
		v++;
		add(v,i);
		add(i,v);
	}
	dfs1(1,1),dfs2(1,1),build(1,1,n);
	for(int i=1,l,r,z;i<=m;i++){
		scanf("%d%d%d",&l,&r,&z);
		l++,r++,z++;
		q[i*2-1]=(_query){l-1,z,i,-1};
		q[i*2]=(_query){r,z,i,1};
	}
	sort(q+1,q+2*m+1,cmp);
	for(int i=1,p=1;i<=m*2;i++){
		if(!q[i].p)continue;
		while(p<=q[i].p)trim(p++,1);
		ans[q[i].id]+=q[i].flag*find(1,q[i].z);
		
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]%p);
	return 0;
}
