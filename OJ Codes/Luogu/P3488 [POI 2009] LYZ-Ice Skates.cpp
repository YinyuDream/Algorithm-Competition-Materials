#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,k,d;
struct node{
	int l,r,lmax,rmax,zmax,sum;
}tree[maxn*4];
void pushup(int id)
{
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].zmax=max(tree[id*2].rmax+tree[id*2+1].lmax,max(tree[id*2].zmax,tree[id*2+1].zmax));
	tree[id].lmax=max(tree[id*2].lmax,tree[id*2].sum+tree[id*2+1].lmax);
	tree[id].rmax=max(tree[id*2+1].rmax,tree[id*2+1].sum+tree[id*2].rmax);
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].lmax=-k;
		tree[id].rmax=-k;
		tree[id].zmax=-k;
		tree[id].sum=-k;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
void update(int id,int pos,int val)
{
	if(tree[id].l==tree[id].r){
		tree[id].lmax+=val;
		tree[id].rmax+=val;
		tree[id].zmax+=val;
		tree[id].sum+=val;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(pos<=mid)update(id*2,pos,val);
	else update(id*2+1,pos,val);
	pushup(id);
}
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	build(1,1,n);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		update(1,x,y);
		if(tree[1].zmax<=k*d)puts("TAK");
		else puts("NIE");
	}
	return 0;
}