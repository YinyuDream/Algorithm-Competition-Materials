#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
struct node{
	int l,r,cnt;
	double mx;
}tree[maxn*4];
int find(int id,double val)
{
	if(tree[id].l==tree[id].r)return tree[id].mx>val;
	if(tree[id].mx<=val)return 0;
	if(tree[id*2].mx<=val)return find(id*2+1,val);
	else return tree[id].cnt-tree[id*2].cnt+find(id*2,val);
}
void pushup(int id)
{
	tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx);
	tree[id].cnt=tree[id*2].cnt+find(id*2+1,tree[id*2].mx);
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void update(int id,int pos,double val)
{
	if(tree[id].l==tree[id].r){
		tree[id].mx=val;
		tree[id].cnt=1;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(pos<=mid)update(id*2,pos,val);
	else update(id*2+1,pos,val);
	pushup(id);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		update(1,x,1.0*y/x);
		printf("%d\n",tree[1].cnt);
	}
	return 0;
}