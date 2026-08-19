#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
struct node{
	int l,r;
	long long add,mul,sum; 
} tree[maxn*4];
int n,m,a[maxn];
long long p;
inline void build(int id,int L,int R){
	tree[id].l=L;tree[id].r=R;tree[id].sum=tree[id].add=0;tree[id].mul=1;
	if(L==R){ tree[id].sum=a[L];return;}
	int mid=(L+R)>>1;
	build(id*2,L,mid);build(id*2+1,mid+1,R);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
inline void down(int id){
	if(tree[id].l<tree[id].r){//非点区间 
		tree[id*2].mul=(tree[id*2].mul*tree[id].mul)%p;
		tree[id*2].add=(tree[id*2].add*tree[id].mul+tree[id].add)%p;
		tree[id*2].sum=(tree[id*2].sum*tree[id].mul+(tree[id*2].r-tree[id*2].l+1)*tree[id].add)%p;
		tree[id*2+1].mul=(tree[id*2+1].mul*tree[id].mul)%p;
		tree[id*2+1].add=(tree[id*2+1].add*tree[id].mul+tree[id].add)%p;
		tree[id*2+1].sum=(tree[id*2+1].sum*tree[id].mul+(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].add)%p;
		tree[id].add=0;tree[id].mul=1;		
	}
}
inline void update(int id,int L,int R,int val,int opt){
	if(tree[id].r<L || tree[id].l>R) return;
	if(tree[id].l>=L && tree[id].r<=R){
		if(opt==1){//乘标记 
			tree[id].mul=(tree[id].mul*val)%p;
			tree[id].add=(tree[id].add*val)%p;
			tree[id].sum=(tree[id].sum*val)%p;
		} else if(opt==2){//加法标记 
			tree[id].add=(tree[id].add+val)%p;
			tree[id].sum=(tree[id].sum+(tree[id].r-tree[id].l+1)*val)%p; 
		} return;
	}
	if(tree[id].add!=0 || tree[id].mul!=1) down(id);//下传标记
	update(id*2,L,R,val,opt);update(id*2+1,L,R,val,opt);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
inline long long query(int id,int L,int R){
	if(tree[id].l>R || tree[id].r<L) return 0;
	if(L<=tree[id].l && tree[id].r<=R) return tree[id].sum;
	if(tree[id].add!=0 || tree[id].mul!=1) down(id);
	return (query(id*2,L,R)+query(id*2+1,L,R))%p;
}
int main()
{
	int x,y,opt,val;
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&opt);
		if(opt==1 || opt==2){
			scanf("%d%d%d",&x,&y,&val);
			update(1,x,y,val,opt);
		} else if(opt==3){
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}
