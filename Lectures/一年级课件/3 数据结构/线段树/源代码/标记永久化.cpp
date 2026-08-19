#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
struct node{
	int l,r,lazy,sum;
}tree[maxn<<2];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(l==r){
		tree[id].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum; 
}
void update(int id,int l,int r,int val)
{
	tree[id].sum+=(r-l+1)*val;
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].lazy+=val;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,val);
	else if(l>mid)update(id*2+1,l,r,val);
	else update(id*2,l,mid,val),update(id*2+1,mid+1,r,val);
}
int query(int id,int l,int r,int lasy)
{	
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum+(tree[id].r-tree[id].l+1)*lasy;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r,lasy+tree[id].lazy);
	else if(l>mid)return query(id*2+1,l,r,lasy+tree[id].lazy);
	else return query(id*2,l,mid,lasy+tree[id].lazy)+query(id*2+1,mid+1,r,lasy+tree[id].lazy);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y,val;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&x,&y,&val);
			update(1,x,y,val);
		}else{
			scanf("%d%d",&x,&y);
			printf("%d\n",query(1,x,y,0));
		}
	}
	return 0;
}
