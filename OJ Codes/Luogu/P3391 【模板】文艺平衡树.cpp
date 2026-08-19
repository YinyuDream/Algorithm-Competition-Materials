#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt,root;
struct node{
	int l,r,lazy,size,key,val;
}tree[maxn];
void pushup(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
void pushdown(int u)
{
	swap(tree[u].l,tree[u].r);
	if(tree[u].l)tree[tree[u].l].lazy^=1;
	if(tree[u].r)tree[tree[u].r].lazy^=1;
	tree[u].lazy=0;
}
int build(int l,int r,int key)
{
	if(l>r)return 0;
	int mid=(l+r)/2,now=++cnt;
	tree[now].val=mid;
	tree[now].size=1;
	tree[now].key=key;
	if(l==r)return now;
	tree[now].l=build(l,mid-1,key+1);
	tree[now].r=build(mid+1,r,key+1);
	pushup(now);
	return now;
}
void split(int u,int val,int &l,int &r)
{
	if(!u){
		l=r=0;
		return ;
	}
	if(tree[u].lazy)pushdown(u);
	if(tree[tree[u].l].size+1<=val){
		l=u;
		split(tree[u].r,val-tree[tree[u].l].size-1,tree[u].r,r);
	}else{
		r=u;
		split(tree[u].l,val,l,tree[u].l);
	}
	pushup(u);
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].lazy)pushdown(l);
	if(tree[r].lazy)pushdown(r);
	if(tree[l].key<=tree[r].key){
		tree[l].r=merge(tree[l].r,r);
		pushup(l);
		return l;
	}else{
		tree[r].l=merge(l,tree[r].l);
		pushup(r);
		return r;
	}
}
void print(int u)
{
	if(tree[u].lazy)pushdown(u);
	if(tree[u].l)print(tree[u].l);
	printf("%d ",tree[u].val);
	if(tree[u].r)print(tree[u].r);
}
int main(){
	//freopen("splay.in","r",stdin);
	//freopen("splay.out","w",stdout);
	scanf("%d%d",&n,&m);
	root=build(1,n,1);;
	for(int i=1,l,r,u,v;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		split(root,r,u,v);
		split(u,l-1,l,r);
		tree[r].lazy^=1;
		root=merge(merge(l,r),v);
	}
	print(root);
	return 0;
}