#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
ll p,a[maxn];
struct node{
	int l,r;
	ll sum,mul,add;
}tree[maxn*4];
void build(int id,int l,int r)
{
	
	tree[id].l=l,tree[id].r=r,tree[id].mul=1;
	if(tree[id].l==tree[id].r){
		tree[id].sum=a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
void pushdown(int id)
{
	if(tree[id].mul!=1){
		(tree[id*2].mul*=tree[id].mul)%=p;
		(tree[id*2+1].mul*=tree[id].mul)%=p;
		(tree[id*2].add*=tree[id].mul)%=p;
		(tree[id*2+1].add*=tree[id].mul)%=p;
		(tree[id*2].sum*=tree[id].mul)%=p;
		(tree[id*2+1].sum*=tree[id].mul)%=p;
		tree[id].mul=1;
	}
	if(tree[id].add){
		(tree[id*2].add+=tree[id].add)%=p;
		(tree[id*2+1].add+=tree[id].add)%=p;
		(tree[id*2].sum+=(tree[id*2].r-tree[id*2].l+1)*tree[id].add)%=p;
		(tree[id*2+1].sum+=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].add)%=p;
		tree[id].add=0;
	}
}
void update(int id,int l,int r,ll c,int opt)
{
	if(tree[id].l==l&&tree[id].r==r){
		if(opt==1){
			(tree[id].add+=c)%=p;
			(tree[id].sum+=(tree[id].r-tree[id].l+1)*c)%=p;
		}else{
			(tree[id].mul*=c)%=p;
			(tree[id].add*=c)%=p;
			(tree[id].sum*=c)%=p;
		}
		return ;
 	}
 	int mid=(tree[id].l+tree[id].r)/2;
 	if(tree[id].mul!=1||tree[id].add)pushdown(id);
 	if(r<=mid)update(id*2,l,r,c,opt);
 	else if(l>mid)update(id*2+1,l,r,c,opt);
 	else update(id*2,l,mid,c,opt),update(id*2+1,mid+1,r,c,opt);
 	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
ll query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum;
	if(tree[id].mul!=1||tree[id].add)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return (query(id*2,l,mid)+query(id*2+1,mid+1,r))%p;
}
int main(){
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n); 
	for(int i=1,opt,l,r;i<=m;i++){
		ll c;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%lld",&l,&r,&c);
			update(1,l,r,c,2);
		}else if(opt==2){
			scanf("%d%d%lld",&l,&r,&c);
			update(1,l,r,c,1);
		}else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,l,r));
		}
	}
	return 0;
}
