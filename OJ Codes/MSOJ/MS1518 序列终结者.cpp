#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt_node,root;
struct node{
	int l,r,val,size,key,lazy,rev,mx;
}tree[maxn];
void pushup(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
	tree[u].mx=tree[u].val;
	if(tree[u].l)tree[u].mx=max(tree[u].mx,tree[tree[u].l].mx);
	if(tree[u].r)tree[u].mx=max(tree[u].mx,tree[tree[u].r].mx);
}
void pushdown(int u)
{
	if(tree[u].rev)
	{
		swap(tree[u].l,tree[u].r);
		if(tree[u].l)tree[tree[u].l].rev^=1;
		if(tree[u].r)tree[tree[u].r].rev^=1;
		tree[u].rev=0;
	}
	if(tree[u].lazy)
	{
		if(tree[u].l)
		tree[tree[u].l].mx+=tree[u].lazy,
		tree[tree[u].l].val+=tree[u].lazy,
		tree[tree[u].l].lazy+=tree[u].lazy;
		if(tree[u].r)
		tree[tree[u].r].mx+=tree[u].lazy,
		tree[tree[u].r].val+=tree[u].lazy,
		tree[tree[u].r].lazy+=tree[u].lazy;
		tree[u].lazy=0;
	}
}
int build(int l,int r,int key)
{
	if(l>r)return 0;
	int now=++cnt_node;
	int mid=(l+r)/2;
	tree[now].key=key;
	if(l==r){
		tree[now].size=1;
		return now;
	}
	tree[now].l=build(l,mid-1,key+1);
	tree[now].r=build(mid+1,r,key+1);
	pushup(now);
	return now;
}
void split(int u,int val,int &l,int &r)
{
	if(u==0){
		l=r=0;
		return ;
	}
	pushdown(u);
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
	pushdown(l);
	pushdown(r);
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
	pushdown(u);
	if(tree[u].l)print(tree[u].l);
	printf("%d ",tree[u].val);
	if(tree[u].r)print(tree[u].r);
}
int main(){
	scanf("%d%d",&n,&m);
	root=build(1,n,1);
	for(int i=1,opt,l,r,u,v,p,t;i<=m;i++)
	{
		scanf("%d%d%d",&opt,&l,&r);
		split(root,r,u,v);
		split(u,l-1,l,r);
		if(opt==1)scanf("%d",&t),tree[r].lazy+=t,tree[r].val+=t,tree[r].mx+=t;
		else if(opt==2)tree[r].rev^=1;
		else pushup(r),printf("%d\n",tree[r].mx);
		root=merge(merge(l,r),v);
	}
	return 0;
}