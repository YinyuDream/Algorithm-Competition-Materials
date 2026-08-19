#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m,p,opt,a[maxn];
struct node{int left,right;ll lazy_add,lazy_mul;ll sum;}tree[4*maxn];
void build(int id,int L,int R){
	tree[id].left=L,tree[id].right=R,tree[id].lazy_add=0,tree[id].lazy_mul=1;
	if(L==R){tree[id].sum=a[L];return;}
	int mid=(L+R)/2;
	build(2*id,L,mid),build(2*id+1,mid+1,R),tree[id].sum=tree[2*id].sum+tree[2*id+1].sum;
}
void down(int id){
	if(tree[id].left!=tree[id].right){
		tree[2*id].lazy_mul=(tree[2*id].lazy_mul*tree[id].lazy_mul)%p;
		tree[2*id].lazy_add=(tree[2*id].lazy_add*tree[id].lazy_mul+tree[id].lazy_add)%p;
		tree[2*id].sum=(tree[2*id].sum*tree[id].lazy_mul+(tree[2*id].right-tree[2*id].left+1)*tree[id].lazy_add)%p;
		tree[2*id+1].lazy_mul=(tree[2*id+1].lazy_mul*tree[id].lazy_mul)%p;
		tree[2*id+1].lazy_add=(tree[2*id+1].lazy_add*tree[id].lazy_mul+tree[id].lazy_add)%p;
		tree[2*id+1].sum=(tree[2*id+1].sum*tree[id].lazy_mul+(tree[2*id+1].right-tree[2*id+1].left+1)*tree[id].lazy_add)%p;
		tree[id].lazy_add=0,tree[id].lazy_mul=1;
	}
}
void update(int id,int L,int R,ll val,int opt){
	if(tree[id].left>R||tree[id].right<L)return ;
	if(tree[id].left>=L&&tree[id].right<=R){
		if(opt==1)tree[id].lazy_mul=(tree[id].lazy_mul*val)%p,tree[id].lazy_add=(tree[id].lazy_add*val)%p,tree[id].sum=(tree[id].sum*val)%p;
		else tree[id].lazy_add=(tree[id].lazy_add+val)%p,tree[id].sum=(tree[id].sum+(tree[id].right-tree[id].left+1)*val)%p;
		return ;	
	}
	if(tree[id].lazy_add!=0||tree[id].lazy_mul!=1)down(id);
	update(2*id,L,R,val,opt),update(2*id+1,L,R,val,opt),tree[id].sum=(tree[2*id].sum+tree[2*id+1].sum)%p;
}
ll query(int id,int L,int R){
	if(tree[id].left>R||tree[id].right<L)return 0;
	if(tree[id].left>=L&&tree[id].right<=R)return tree[id].sum;
	if(tree[id].lazy_add!=0||tree[id].lazy_mul!=1)down(id);
	return (query(id*2,L,R)+query(id*2+1,L,R))%p;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);build(1,1,n);scanf("%d",&opt);
	for(int i=1,x,y,k;i<=m;i++,scanf("%d",&opt)){
		if((opt+1)/2==1)scanf("%d%d%d",&x,&y,&k),update(1,x,y,k,opt);
		else scanf("%d%d",&x,&y),printf("%lld\n",query(1,x,y));
		if(i==m)return 0;
	}
	return 0;
}
