#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int l,r,lazy,sum;
	int lson,rson;
}tree[maxn<<1];
int a[maxn];
int build(int l,int r)
{
	int t=++k;
	tree[t].l=l,tree[t].r=r;
	if(l==r){
		tree[t].sum=a[l];
		return t;
	}
	int mid=(l+r)/2;
	tree[t].lson=build(l,mid),tree[t].rson=build(mid+1,r);
	tree[t].sum=tree[tree[t].lson].sum+tree[tree[t].rson].sum;
	return t;
}
void pushdown(int id)
{
	tree[tree[id].lson].lazy+=tree[id].lazy;
	tree[tree[id].lson].sum+=(tree[tree[id].lson].r-tree[tree[id].lson].l+1)*tree[id].lazy;
	tree[tree[id].rson].lazy+=tree[id].lazy;
	tree[tree[id].rson].sum+=(tree[tree[id].rson].r-tree[tree[id].rson].l+1)*tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int val)
{
	if(tree[id].r<l||tree[id].l>r)return ;
	if(tree[id].l>=l&&tree[id].r<=r){
		tree[id].lazy+=val;
		tree[id].sum+=(tree[id].r-tree[id].l+1)*val;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	update(tree[id].lson,l,r,val),update(tree[id].rson,l,r,val);
	tree[id].sum=tree[tree[id].lson].sum+tree[tree[id].rson].sum;
}
int query(int id,int l,int r)
{
	if(tree[id].r<l||tree[id].l>r)return 0;
	if(tree[id].l>=l&&tree[id].r<=r)return tree[id].sum;
	if(tree[id].lazy)pushdown(id);
	return query(tree[id].lson,l,r)+query(tree[id].rson,l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,val;
		scanf("%d",&opt);
		if(opt==1)scanf("%d%d%d",&x,&y,&val),update(root,x,y,val);
		else scanf("%d%d",&x,&y),printf("%d\n",query(root,x,y));
	}
	return 0;
}
