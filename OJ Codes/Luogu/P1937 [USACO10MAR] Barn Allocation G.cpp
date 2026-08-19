#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,ans;
int c[maxn];
struct seg{
	int l,r;
}e[maxn];
bool cmp(seg a,seg b)
{
	if(a.r!=b.r)
	return a.r<b.r;
	return a.l>b.l;
}
struct node{
	int l,r,lazy,minx;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r)
	{
		tree[id].minx=c[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx);
}
void pushdown(int id)
{
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2].minx-=tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2+1].minx-=tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int num) 
{
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].minx-=num;
		tree[id].lazy+=num;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,num);
	else if(l>=mid+1)update(id*2+1,l,r,num);
	else update(id*2,l,mid,num),update(id*2+1,mid+1,r,num);
	tree[id].minx=min(tree[id*2].minx,tree[id*2+1].minx); 
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	return tree[id].minx;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>=mid+1)return query(id*2+1,l,r);
	else return min(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&e[i].l,&e[i].r);
	sort(e+1,e+m+1,cmp);
	build(1,1,n);
	
	for(int i=1;i<=m;i++)
	{
		if(query(1,e[i].l,e[i].r)<=0)continue;
		update(1,e[i].l,e[i].r,1);
		ans++;
	}
	printf("%d",ans);
	return 0;
}
