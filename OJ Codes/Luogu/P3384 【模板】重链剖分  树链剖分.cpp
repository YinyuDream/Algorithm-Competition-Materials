#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,r,p,k,num;
int a[maxn],head[maxn];
int fa[maxn],son[maxn],deep[maxn],size[maxn],news[maxn],old[maxn],top[maxn];
struct Edge{
	int to,next;
}edge[maxn<<1];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs1(int u,int f)
{
	size[u]=1;
	fa[u]=f;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			dfs1(v,u);
			size[u]+=size[v];
			if(size[son[u]]<size[v]){
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
	if(son[u]){dfs2(son[u],tp);
	}
	
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u]){
			dfs2(v,v);
		}
	}
}
struct node{
	int l,r,len;
	long long sum,lazy;
}tree[maxn<<2];
void build(int id,int l,int r)
{
	tree[id].l=l;
	tree[id].r=r;
	tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r){
		tree[id].sum=a[old[l]];
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
void pushdown(int id)
{
	tree[id*2].lazy=(tree[id].lazy+tree[id*2].lazy)%p;
	tree[id*2].sum=(tree[id].lazy*tree[id*2].len+tree[id*2].sum)%p;
	tree[id*2+1].lazy=(tree[id].lazy+tree[id*2+1].lazy)%p;
	tree[id*2+1].sum=(tree[id].lazy*tree[id*2+1].len+tree[id*2+1].sum)%p;
	tree[id].lazy=0;
}
void update(int id,int l,int r,long long val)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].sum=(tree[id].sum+val*tree[id].len)%p;
		tree[id].lazy=(tree[id].lazy+val)%p;
		return ;
	}
	if(tree[id].lazy){
		pushdown(id);
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid){
		update(id*2,l,r,val);
	}else if(l>mid){
		update(id*2+1,l,r,val);
	}else{
		update(id*2,l,mid,val);
		update(id*2+1,mid+1,r,val);
	}
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
long long query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r){
		return tree[id].sum%p;
	}
	if(tree[id].lazy){
		pushdown(id);
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid){
		return query(id*2,l,r)%p;
	}else if(l>mid){
		return query(id*2+1,l,r)%p;
	}else{
		return (query(id*2,l,mid)+query(id*2+1,mid+1,r))%p;
	}
}
void trim(int u,int v,long long val)
{
	
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
		update(1,news[top[u]],news[u],val);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v]){
		swap(u,v);
	}
	update(1,news[u],news[v],val);
}
long long find(int u,int v)
{
	long long ans=0;
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]]){
			swap(u,v);
		}
		ans=(ans+query(1,news[top[u]],news[u]))%p;
		u=fa[top[u]];
	}
	if(deep[u]<deep[v]){
		swap(u,v);
	}
	ans+=query(1,news[v],news[u]);
	return ans%p;
}
main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&r,&p);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]%=p;
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(r,r);
	dfs2(r,r);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		long long z;
		scanf("%lld",&opt);
		if(opt==1){
			scanf("%lld%lld%lld",&x,&y,&z);
			trim(x,y,z);
		}else if(opt==2){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",find(x,y));
		}else if(opt==3){
			scanf("%lld%lld",&x,&z);
			update(1,news[x],news[x]+size[x]-1,z);
		}else if(opt==4){
			scanf("%lld",&x);
			printf("%lld\n",query(1,news[x],news[x]+size[x]-1));
		}
	}
	return 0;
}
