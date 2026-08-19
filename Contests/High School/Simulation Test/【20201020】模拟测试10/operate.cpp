#include<cstdio>
using namespace std;
const int maxn=2e5+10;
int n,k,m;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn],w[maxn];
void add_edge(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
namespace subtask1
{
	void add(int u,int f,int pos,int val)
	{
		if(u==pos){
			w[++n]=val;
			add_edge(pos,n);
			add_edge(n,pos);
			return ;
		}
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				add(v,u,pos,val);
			}
		}
	}
	void del(int u,int f,int pos)
	{
		int pre=head[u];
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v==f)continue;
			if(v==pos){
				edge[pre].next=edge[i].next;
				return ;
			}
			del(v,u,pos);
			pre=i;
		}
	}
	void update(int u,int f,int pos,int val,int book)
	{
		if(book)w[u]+=val;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				update(v,u,pos,val,book||v==pos);
			}
		}
	}
	int query(int u,int f,int pos,bool book)
	{
		int sum=0;
		if(book)sum+=w[u];
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				sum+=query(v,u,pos,book||v==pos);
			}
		}
		return sum;	
	}
	void work()
	{
		for(int i=1,opt,x,y;i<=m;i++)
		{
			scanf("%d%d",&opt,&x);
			if(opt==1){
				scanf("%d",&y);
				add(1,1,x,y);
			}else if(opt==2){
				del(1,1,x);
			}else if(opt==3){
				scanf("%d",&y);
				update(1,1,x,y,0||x==1);
			}else{
				printf("%d\n",query(1,1,x,0||x==1));
			}
		}
	}
}
namespace subtask2
{
	int dfn[maxn],size[maxn],num[maxn],top;
	struct seg{
		int l,r,sum,lazy;
	}tree[maxn*2];
	void dfs(int u,int f)
	{
		dfn[u]=++top;
		num[top]=w[u];
		size[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				dfs(v,u);
				size[u]+=size[v];
			}
		}
	}
	void build(int id,int l,int r)
	{
		tree[id].l=l,tree[id].r=r;
		if(tree[id].l==tree[id].r){
			tree[id].sum=num[l];
			return;
		}
		int mid=(tree[id].l+tree[id].r)/2;
		build(id*2,l,mid),build(id*2+1,mid+1,r);
		tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	}
	void pushdown(int id)
	{
		tree[id*2].lazy+=tree[id].lazy;
		tree[id*2+1].lazy+=tree[id].lazy;
		tree[id*2].sum+=tree[id].lazy*(tree[id*2].r-tree[id*2].l+1);
		tree[id*2+1].sum+=tree[id].lazy*(tree[id*2+1].r-tree[id*2+1].l+1);
		tree[id].lazy=0;
	}
	void update(int id,int l,int r,int c)
	{
		if(tree[id].l==l&&tree[id].r==r){
			tree[id].lazy+=c;
			tree[id].sum+=(tree[id].r-tree[id].l+1)*c;
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
	void work()
	{
		dfs(1,1),build(1,1,n);
		for(int i=1,opt,x,y;i<=m;i++)
		{
			scanf("%d%d",&opt,&x);
			if(opt==3)scanf("%d",&y),update(1,dfn[x],dfn[x]+size[x]-1,y);
			else if(opt==4)printf("%d\n",query(1,dfn[x],dfn[x]+size[x]-1));
		}
	}
}
int main(){
	freopen("operate.in","r",stdin);
	freopen("operate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
	scanf("%d",&m);
	if(n<=1000)subtask1::work();
	else subtask2::work();
	return 0;
}
