#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m;
int a[maxn];
struct node{
	int len,l,r,lazy,lazy_rev,zmax0,zmax1,lmax0,lmax1,rmax0,rmax1,sum0,sum1;
}tree[maxn*4];
void pushup(int id)
{
	tree[id].sum0=tree[id*2].sum0+tree[id*2+1].sum0;
	tree[id].sum1=tree[id*2].sum1+tree[id*2+1].sum1;
	tree[id].zmax0=max(tree[id*2].rmax0+tree[id*2+1].lmax0,max(tree[id*2].zmax0,tree[id*2+1].zmax0));
	tree[id].zmax1=max(tree[id*2].rmax1+tree[id*2+1].lmax1,max(tree[id*2].zmax1,tree[id*2+1].zmax1));
	tree[id].lmax0=tree[id*2].lmax0+(tree[id*2].lmax0==tree[id*2].len)*tree[id*2+1].lmax0;
	tree[id].lmax1=tree[id*2].lmax1+(tree[id*2].lmax1==tree[id*2].len)*tree[id*2+1].lmax1;
	tree[id].rmax0=tree[id*2+1].rmax0+(tree[id*2+1].rmax0==tree[id*2+1].len)*tree[id*2].rmax0;
	tree[id].rmax1=tree[id*2+1].rmax1+(tree[id*2+1].rmax1==tree[id*2+1].len)*tree[id*2].rmax1;
}
void pushdown(int id)
{
	if(tree[id].lazy!=-1){
		tree[id].lazy_rev=tree[id*2].lazy_rev=tree[id*2+1].lazy_rev=0;
		tree[id*2].sum0=tree[id*2].lmax0=tree[id*2].rmax0=tree[id*2].zmax0=tree[id*2].len*(tree[id].lazy^1);
		tree[id*2+1].sum0=tree[id*2+1].lmax0=tree[id*2+1].rmax0=tree[id*2+1].zmax0=tree[id*2+1].len*(tree[id].lazy^1);
		tree[id*2].sum1=tree[id*2].lmax1=tree[id*2].rmax1=tree[id*2].zmax1=tree[id*2].len*tree[id].lazy;
		tree[id*2+1].sum1=tree[id*2+1].lmax1=tree[id*2+1].rmax1=tree[id*2+1].zmax1=tree[id*2+1].len*tree[id].lazy;
		tree[id*2].lazy=tree[id*2+1].lazy=tree[id].lazy;
		tree[id].lazy=-1;
	}
	if(tree[id].lazy_rev){
		if(tree[id*2].lazy!=-1)tree[id*2].lazy^=1;
		else tree[id*2].lazy_rev^=1;
		if(tree[id*2+1].lazy!=-1)tree[id*2+1].lazy^=1;
		else tree[id*2+1].lazy_rev^=1;
		swap(tree[id*2].sum0,tree[id*2].sum1);
		swap(tree[id*2].lmax0,tree[id*2].lmax1);
		swap(tree[id*2].zmax0,tree[id*2].zmax1);
		swap(tree[id*2].rmax0,tree[id*2].rmax1);
		swap(tree[id*2+1].sum0,tree[id*2+1].sum1);
		swap(tree[id*2+1].lmax0,tree[id*2+1].lmax1);
		swap(tree[id*2+1].zmax0,tree[id*2+1].zmax1);
		swap(tree[id*2+1].rmax0,tree[id*2+1].rmax1);
		tree[id].lazy_rev=0;
	}
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r,tree[id].len=r-l+1,tree[id].lazy=-1;
	if(tree[id].l==tree[id].r){
		tree[id].lmax1=tree[id].rmax1=tree[id].zmax1=tree[id].sum1=a[l];
		tree[id].lmax0=tree[id].rmax0=tree[id].zmax0=tree[id].sum0=!a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
void cover0(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].zmax1=tree[id].lmax1=tree[id].rmax1=tree[id].sum1=0;
		tree[id].zmax0=tree[id].lmax0=tree[id].rmax0=tree[id].sum0=tree[id].len;
		tree[id].lazy=0;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)cover0(id*2,l,r);
	else if(l>mid)cover0(id*2+1,l,r);
	else cover0(id*2,l,mid),cover0(id*2+1,mid+1,r);
	pushup(id);
}
void cover1(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].zmax1=tree[id].lmax1=tree[id].rmax1=tree[id].sum1=tree[id].len;
		tree[id].zmax0=tree[id].lmax0=tree[id].rmax0=tree[id].sum0=0;
		tree[id].lazy=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)cover1(id*2,l,r);
	else if(l>mid)cover1(id*2+1,l,r);
	else cover1(id*2,l,mid),cover1(id*2+1,mid+1,r);
	pushup(id);
}
void rev(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r){
		swap(tree[id].sum0,tree[id].sum1);
		swap(tree[id].zmax0,tree[id].zmax1);
		swap(tree[id].lmax0,tree[id].lmax1);
		swap(tree[id].rmax0,tree[id].rmax1);
		tree[id].lazy_rev^=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)rev(id*2,l,r);
	else if(l>mid)rev(id*2+1,l,r);
	else rev(id*2,l,mid),rev(id*2+1,mid+1,r);
	pushup(id);
}
int query_sum(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum1;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query_sum(id*2,l,r);
	else if(l>mid)return query_sum(id*2+1,l,r);
	else return query_sum(id*2,l,mid)+query_sum(id*2+1,mid+1,r);
}
node query_len(int id,int l,int r)
{
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)return tree[id];
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query_len(id*2,l,r);
	else if(l>mid)return query_len(id*2+1,l,r);
	else{
		node t1=query_len(id*2,l,mid),t2=query_len(id*2+1,mid+1,r),t3;
		t3.len=t1.len+t2.len;
		t3.zmax1=max(t1.rmax1+t2.lmax1,max(t1.zmax1,t2.zmax1));
		t3.lmax1=t1.lmax1+(t1.lmax1==t1.len)*t2.lmax1;
		t3.rmax1=t2.rmax1+(t2.rmax1==t2.len)*t1.rmax1;
		return t3;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	build(1,0,n-1);
	for(int i=1,opt,l,r;i<=m;i++)
	{
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==0)cover0(1,l,r);
		else if(opt==1)cover1(1,l,r);
		else if(opt==2)rev(1,l,r);
		else if(opt==3)printf("%d\n",query_sum(1,l,r));
		else printf("%d\n",query_len(1,l,r).zmax1);
	}
	return 0;
}
