#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,q;
struct node{
	int l,r,state,lazy;
}tree[maxn*4];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].state=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].state=tree[id*2].state|tree[id*2+1].state;
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id*2+1].lazy=tree[id].lazy;
	tree[id*2].state=tree[id*2+1].state=1<<(tree[id].lazy-1);
	tree[id].lazy=0;
}
void update(int id,int l,int r,int c){
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].state=1<<(c-1);
		tree[id].lazy=c;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	tree[id].state=tree[id*2].state|tree[id*2+1].state;
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].state;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return query(id*2,l,mid)|query(id*2+1,mid+1,r);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	build(1,1,n);
	for(int i=1,l,r,c;i<=q;i++)
	{
		char opt;
		scanf("\n%c%d%d",&opt,&l,&r);
		if(l>r)swap(l,r);
		if(opt=='C'){
			scanf("%d",&c);
			update(1,l,r,c);
		}else{
			int t=0,ans=query(1,l,r);
			for(int i=1;i<=30;i++)
				if(ans&(1<<(i-1)))
					t++;
			printf("%d\n",t);
		}
	}
	return 0;
}
