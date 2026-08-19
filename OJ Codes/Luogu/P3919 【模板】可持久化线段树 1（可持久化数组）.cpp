#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int root[maxn],a[maxn];
struct node{
	int l,r,val;
}tree[30*maxn];
int build(int l,int r)
{
	int now=++k;
	if(l==r){
		tree[now].val=a[l];
		return now;
	}
	int mid=(l+r)/2;
	tree[now].l=build(l,mid);
	tree[now].r=build(mid+1,r);
	return now;
}
int update(int pre,int l,int r,int x,int y)
{
	int now=++k;
	tree[now]=tree[pre];
	if(l==r){
		tree[now].val=y;
		return now;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	tree[now].l=update(tree[pre].l,l,mid,x,y);
	else
	tree[now].r=update(tree[pre].r,mid+1,r,x,y);
	return now;
}
int query(int pre,int l,int r,int x)
{
	if(l==r)
	return tree[pre].val;
	int mid=(l+r)/2;
	if(x<=mid)
	return query(tree[pre].l,l,mid,x);
	else
	return query(tree[pre].r,mid+1,r,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	root[0]=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int old,opt,x,y;
		scanf("%d%d",&old,&opt);
		if(opt==1)
		scanf("%d%d",&x,&y),
		root[i]=update(root[old],1,n,x,y);
		else
		scanf("%d",&x),
		printf("%d\n",query(root[old],1,n,x)),
		root[i]=root[old];
	} 
	return 0;
}
