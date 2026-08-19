#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn],z[maxn],top;
struct node{
	int l,r,mx,len;
}tree[maxn*4];
int getlen(int id,int x)
{
	if(tree[id].mx<=x)return 0;
	if(tree[id].l==tree[id].r)return 1;
	if(x>tree[id*2].mx)return getlen(id*2+1,x);
	else return tree[id].len-tree[id*2].len+getlen(id*2,x);
}
void pushup(int id)
{
	tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx);
	tree[id].len=tree[id*2].len+getlen(id*2+1,tree[id*2].mx);
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].mx=a[l];
		tree[id].len=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
void update(int id,int p,int val)
{
	if(tree[id].l==p&&tree[id].r==p){
		tree[id].mx=val;
		tree[id].len=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(p<=mid)update(id*2,p,val);
	else update(id*2+1,p,val);
	pushup(id);
}
void query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r){
		z[++top]=id;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)query(id*2,l,r);
	else if(l>mid)query(id*2+1,l,r);
	else query(id*2,l,mid),query(id*2+1,mid+1,r);
}
int find(int l,int r)
{
	int cnt=0,mx=-0x7f7f7f7f;
	top=0;
	query(1,l,r);
	for(int i=1;i<=top;i++)
	{
		cnt+=getlen(z[i],mx);
		mx=max(mx,tree[z[i]].mx);
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1,opt,x,y;i<=m;i++)
	{
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)printf("%d\n",find(x,y));
		else update(1,x,y);
	}
	return 0;
}
