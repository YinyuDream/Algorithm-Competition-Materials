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
#define int long long
using namespace std;
const int maxn=3e5+10;
int n,m,cnt,q,root[maxn];
struct node{
	int l,r,lson,rson,size,num;
}tree[maxn*30];
int build(int l,int r)
{
	int now=++cnt;
	tree[now].l=l,tree[now].r=r,tree[now].size=r-l+1;
	return now;
}
int del1(int id,int k)
{
	if(tree[id].l==tree[id].r){
		tree[id].size=0;
		if(!tree[id].num)return tree[id].l;
		else return tree[id].num;
	}
	int mid=(tree[id].l+tree[id].r)/2,ans;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(k<=tree[tree[id].lson].size)ans=del1(tree[id].lson,k);
	else ans=del1(tree[id].rson,k-tree[tree[id].lson].size);
	tree[id].size=tree[tree[id].lson].size+tree[tree[id].rson].size;
	return ans;
}
int del2(int id,int k)
{
	if(tree[id].l==tree[id].r){
		tree[id].size=0;
		if(!tree[id].num)return tree[id].l*m;
		else return tree[id].num;
	}
	int mid=(tree[id].l+tree[id].r)/2,ans=0;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(k<=tree[tree[id].lson].size)ans=del2(tree[id].lson,k);
	else ans=del2(tree[id].rson,k-tree[tree[id].lson].size);
	tree[id].size=tree[tree[id].lson].size+tree[tree[id].rson].size;
	return ans;
}
void add(int id,int kth,int val)
{
	if(tree[id].l==tree[id].r){
		tree[id].size=1;
		tree[id].num=val;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(kth<=tree[tree[id].lson].size)add(tree[id].lson,kth,val);
	else add(tree[id].rson,kth-tree[tree[id].lson].size,val);
	tree[id].size=tree[tree[id].lson].size+tree[tree[id].rson].size;
}
main(){
	//freopen("phalanx.in","r",stdin);
	//freopen("phalanx.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)
		root[i]=build((i-1)*m+1,i*m+q);
	root[n+1]=build(1,n+q);
	for(int i=1,x,y,t1,t2;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(y<m){
			t1=del1(root[x],y);
			t2=del2(root[n+1],x);
			add(root[x],m-1,t2);
			add(root[n+1],n,t1);	
		}else{
			t1=del2(root[n+1],x);
			add(root[n+1],n,t1);
		}
		printf("%lld\n",t1);
	}
	return 0;
}