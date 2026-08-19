#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
struct node{
	int l,r,lazy,sum;
}tree[maxn*4];
void pushdown(int id)
{
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2].sum+=(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2+1].sum+=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy;
	tree[id].lazy=0;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(l==r){
		tree[id].sum=a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum; 
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
	update(id*2,l,r,val),update(id*2+1,l,r,val);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id,int l,int r)
{
	if(tree[id].r<l||tree[id].l>r)return 0;
	if(tree[id].l>=l&&tree[id].r<=r)return tree[id].sum;
	if(tree[id].lazy)pushdown(id);
	return 	query(id*2,l,r)+query(id*2+1,l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				scanf("%d%d%d",&x,&y,&k);
				update(1,x,y,k);
				break;
			case 2:
				scanf("%d%d",&x,&y);
				printf("%d\n",query(1,x,y));
				break;
		}
	}
	return 0;
}
