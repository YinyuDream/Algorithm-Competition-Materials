#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
const int maxn=1e6+10;
int n,m,k;
struct graph{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int fa[maxn],size[maxn],dfn[maxn],old[maxn],cnt;
void dfs(int u)
{
	dfn[u]=++cnt;
	old[cnt]=u;
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa[u]){
			dfs(v);
			size[u]+=size[v];
		}
	}
}
struct segment_tree{
	int l,r,pos;
	uint sum,lazy;
}tree[maxn*4];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void pushdown(int id)
{
	tree[id*2].sum+=tree[id].lazy*(tree[id*2].r-tree[id*2].l+1);
	tree[id*2+1].sum+=tree[id].lazy*(tree[id*2+1].r-tree[id*2+1].l+1);
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,uint c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].sum+=c*(tree[id].r-tree[id].l+1);
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
uint query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	return tree[id].sum;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
void change(int id,int pos,int val)
{
	if(tree[id].l==tree[id].r){
		if(val==1)tree[id].pos=pos;
		else tree[id].pos=0;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(pos<=mid)change(id*2,pos,val);
	else change(id*2+1,pos,val);
	if(tree[id*2].pos)tree[id].pos=tree[id*2].pos;
	else tree[id].pos=tree[id*2+1].pos;
}
int find(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].pos;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return find(id*2,l,r);
	else if(l>mid)return find(id*2+1,l,r);
	else {
		int pos=find(id*2,l,mid);
		if(!pos)return find(id*2+1,mid+1,r);
		else return pos;
	}
}
int main(){
	freopen("pastel.in","r",stdin);
	freopen("pastel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(fa[i],i);
		add(i,fa[i]);
	}
	dfs(1),build(1,1,n),change(1,1,1);
	for(int i=1,opt,x,l,r;i<=m;i++){
		uint y;
		scanf("%d%d",&opt,&x);
		if(opt==1){
			printf("%u\n",query(1,dfn[x],dfn[x]));
		}else if(opt==2){
			scanf("%u",&y);
			l=dfn[x],r=dfn[x]+size[x]-1;
			update(1,l,r,y);
			l++;
			while(l<=r){
				int p=find(1,l,r);
				if(!p)break;
				l=p+size[old[p]];
				update(1,p,l-1,0-y);
			}
		}else if(opt==3){
			printf("%u\n",query(1,dfn[x],dfn[x]+size[x]-1));
		}else if(opt==4){
			scanf("%u",&y);
			l=dfn[x],r=dfn[x]+size[x]-1;
			while(l<=r){
				int p=find(1,l,r);
				if(!p)break;
				l=p+size[old[p]];
				update(1,p,l-1,y);
			}
		}else if(opt==5){
			change(1,dfn[x],1);
		}else if(opt==6){
			change(1,dfn[x],0);
		}
	}
	return 0;
}//¸´ÔÓ¶È´íÎó×ö·¨ 
