#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
double a[maxn];
struct node{
	int l,r;
	double sum,sum_pow,lazy;
}tree[maxn*4];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].sum=a[l];
		tree[id].sum_pow=a[l]*a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].sum_pow=tree[id*2].sum_pow+tree[id*2+1].sum_pow;
}
void pushdown(int id)
{
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2].sum_pow+=2*tree[id].lazy*tree[id*2].sum+(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy*tree[id].lazy;
	tree[id*2+1].sum_pow+=2*tree[id].lazy*tree[id*2+1].sum+(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy*tree[id].lazy;
	tree[id*2].sum+=(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy;
	tree[id*2+1].sum+=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,double c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].lazy+=c;
		tree[id].sum_pow+=2*tree[id].sum*c+(tree[id].r-tree[id].l+1)*c*c;
		tree[id].sum+=(tree[id].r-tree[id].l+1)*c;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].sum_pow=tree[id*2].sum_pow+tree[id*2+1].sum_pow;
}
node query(int id,int l,int r){
	
	if(tree[id].l==l&&tree[id].r==r)return tree[id];
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else{
		node t1=query(id*2,l,mid),t2=query(id*2+1,mid+1,r),t3;
		t3.sum=t1.sum+t2.sum;
		t3.sum_pow=t1.sum_pow+t2.sum_pow;
		return t3;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	build(1,1,n);
	for(int i=1,opt,x,y;i<=m;i++)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			double z;
			scanf("%lf",&z);
			update(1,x,y,z);
		}else{
			node t=query(1,x,y);
			if(opt==2){
				printf("%.4f\n",t.sum/(y-x+1));
			}else{
				printf("%.4f\n",(t.sum_pow-2*(t.sum/(y-x+1))*t.sum+(y-x+1)*(t.sum/(y-x+1))*(t.sum/(y-x+1)))/(y-x+1));
			}
		}
	}
	return 0;
}
