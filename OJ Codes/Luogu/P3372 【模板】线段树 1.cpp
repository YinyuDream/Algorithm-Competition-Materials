#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int n,m;
struct node{
	int lef,rig,sum,lazy;
}tree[4*maxn];
int a[maxn];
void down(int id){tree[2*id].lazy+=tree[id].lazy,tree[2*id].sum+=(tree[2*id].rig-tree[2*id].lef+1)*tree[id].lazy,tree[2*id+1].lazy+=tree[id].lazy,tree[2*id+1].sum+=(tree[2*id+1].rig-tree[2*id+1].lef+1)*tree[id].lazy,tree[id].lazy=0;}
void build(int L,int R,int id){
	tree[id].lef=L,tree[id].rig=R,tree[id].sum=tree[id].lazy=0;
	if(L==R){tree[id].sum=a[L];return;}
	int mid=(L+R)/2;
	build(L,mid,id*2);build(mid+1,R,id*2+1);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void update(int id,int L,int R,int val){
	if(tree[id].lef>R||tree[id].rig<L)return ;
	if(tree[id].lef>=L&&tree[id].rig<=R){tree[id].lazy+=val,tree[id].sum+=(tree[id].rig-tree[id].lef+1)*val;return ;}
	if(tree[id].lazy)down(id);
	update(id*2,L,R,val);update(id*2+1,L,R,val);tree[id].sum=tree[2*id].sum+tree[2*id+1].sum;	
}
int query(int id,int L,int R){
	if(tree[id].lef>R||tree[id].rig<L)return 0;
	if(tree[id].lef>=L&&tree[id].rig<=R)return tree[id].sum;
	if(tree[id].lazy)down(id);
	return query(id*2,L,R)+query(id*2+1,L,R);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int opt,x,y,k;scanf("%d",&opt);
		if(opt==1)scanf("%d%d%d",&x,&y,&k),update(1,x,y,k);
		else scanf("%d%d",&x,&y),printf("%d\n",query(1,x,y));		
	}
	return 0;
}
