#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e6+10;
int n,q,k,root=1,top;
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
struct Segment_Tree{
	int l,r,minx;
}tree[maxn*4];
int a[maxn],deep[maxn],size[maxn],dfn[maxn],num[maxn],fa[maxn][20];
void dfs(int u,int f)
{
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	dfn[u]=++top;
	num[top]=a[u];
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].minx=num[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx);
}
void update(int id,int pos,int val)
{
	if(tree[id].l==tree[id].r){
		tree[id].minx=val;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(pos<=mid)update(id*2,pos,val);
	else update(id*2+1,pos,val);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx);
}
int query(int id,int l,int r)
{
	if(l>r)return 0x3f3f3f3f;
	if(tree[id].l==l&&tree[id].r==r)return tree[id].minx;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return min(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
int calc(int u,int v)
{
	int delta=deep[u]-deep[v]-1;
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			u=fa[u][i];
	return u;
}
int main(){
	freopen("tree10.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1,v;i<=n;i++){
		scanf("%d%d",&v,&a[i]);
		if(v)add(v,i),add(i,v);
	}
	dfs(1,1);
	build(1,1,n);
	for(int i=1,x,y;i<=q;i++){
		char opt;
		scanf("\n%c ",&opt);
		if(opt=='V'){
			scanf("%d%d",&x,&y);
			update(1,dfn[x],y);
		}else if(opt=='E'){
			scanf("%d",&x);
			root=x;
		}else{
			scanf("%d",&x);
			if(x==root)printf("%d\n",query(1,1,n));
			else if(dfn[root]>dfn[x]&&dfn[root]<=dfn[x]+size[x]-1){
				int t=calc(root,x);
				printf("%d\n",min(query(1,1,dfn[t]-1),query(1,dfn[t]+size[t],n)));
			}
			else printf("%d\n",query(1,dfn[x],dfn[x]+size[x]-1));
		}
	}
	return 0;
}
