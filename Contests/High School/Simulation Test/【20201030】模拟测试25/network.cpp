#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6+10,p=2019;
int n,q,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
int fa[maxn],deep[maxn],size[maxn],top[maxn],tid[maxn],old[maxn],son[maxn],e[maxn],cnt;
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			e[v]=edge[i].wt;
			deep[v]=deep[u]+1;
			dfs(v,u);
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
		if(v!=son[u]&&v!=fa[u]){
			dfs2(v,v);
		}
	}
}
struct segment_tree{
	int l,r,lazy,sum,psum,sz,psz;
}tree[maxn];
void pushup(int id)
{
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
	tree[id].psum=(tree[id*2].psum+tree[id*2+1].psum)%p;
}
void pushdown(int id)
{
	tree[id*2].sum+=tree[id*2].sz*tree[id].lazy;
	tree[id*2].psum+=tree[id*2].psz*tree[id].lazy;
	tree[id*2+1].sum+=tree[id*2+1].sz*tree[id].lazy;
	tree[id*2+1].psum+=tree[id*2+1].psz*tree[id].lazy;
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2].sum%=p;
	tree[id*2+1].sum%=p;
	tree[id*2].psum%=p;
	tree[id*2+1].psum%=p;
	tree[id*2].lazy%=p;
	tree[id*2+1].lazy%=p;
	tree[id].lazy=0;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].sum=size[old[l]]*e[old[l]]%p;
		tree[id].psum=size[old[l]]*size[old[l]]*e[old[l]]%p;
		tree[id].sz=size[old[l]]%p;
		tree[id].psz=size[old[l]]*size[old[l]]%p;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
	tree[id].sz=(tree[id*2].sz+tree[id*2+1].sz)%p;
	tree[id].psz=(tree[id*2].psz+tree[id*2+1].psz)%p;
}
void update(int id,int l,int r,int c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].sum+=tree[id].sz*c;
		tree[id].psum+=tree[id].psz*c;
		tree[id].lazy+=c;
		tree[id].sum%=p;
		tree[id].psum%=p;
		tree[id].lazy%=p;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	pushup(id);
}
pii query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return make_pair(tree[id].sum%p,tree[id].psum%p);
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else{
		pii t1=query(id*2,l,mid),t2=query(id*2+1,mid+1,r),t3;
		return make_pair((t1.first+t2.first)%p,(t1.second+t2.second)%p);
	}
}
void trim(int u,int v,int w)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		update(1,tid[top[u]],tid[u],w);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	if(tid[u]<tid[v])
	update(1,tid[u]+1,tid[v],w);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2,w;i<=n;i++){
		scanf("%d%d",&fa[i],&w);
		add(i,fa[i],w);
		add(fa[i],i,w);
	}
	dfs(1,1),dfs2(1,1),build(1,1,n);
	for(int i=1,u,v,w;i<=q;i++){
		string opt;
		cin>>opt;
		if(opt=="INC"){
			scanf("%d%d%d",&u,&v,&w);
			trim(u,v,w);
		}else{
			scanf("%d",&u);
			pii t=query(1,tid[u],tid[u]+size[u]-1);
			printf("%d\n",((size[u]*t.first-t.second)%p+p)%p);
		}
	}
	return 0;
}
