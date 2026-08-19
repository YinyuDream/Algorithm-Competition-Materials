#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=3e7+10;
int n,m,k;
int a[maxn],sum[maxn];
struct tire{
	int size,son[2];
}tree[maxn];
int root[maxn];
int build(int x)
{
	int now=++k;
	tree[now].size=1;
	if(x==0)return now;
	tree[now].son[0]=build(x-1);
	return now;	
}
int update(int pre,int x,int pos)
{
	int now=++k;
	if(pos==0){
		tree[now].size=tree[pre].size+1;
		return now;
	}
	//if(!tree[pre].son[0])tree[pre].son[0]=++k;
	//if(!tree[pre].son[1])tree[pre].son[1]=++k;
	tree[now]=tree[pre];
	tree[now].son[1&(x>>(pos-1))]=update(tree[pre].son[1&(x>>(pos-1))],x,pos-1);
	tree[now].size=tree[tree[now].son[0]].size+tree[tree[now].son[1]].size;
	return now;
}
int query(int pre,int now,int x,int pos)
{
	if(!pos)return 0;
	//if(!tree[pre].son[0])tree[pre].son[0]=++k;
	//if(!tree[pre].son[1])tree[pre].son[1]=++k;
	//if(!tree[now].son[0])tree[now].son[0]=++k;
	//if(!tree[now].son[1])tree[now].son[1]=++k;
	return (tree[tree[now].son[1^(1&(x>>(pos-1)))]].size-tree[tree[pre].son[1^(1&(x>>(pos-1)))]].size)?
			query(tree[pre].son[1^(1&(x>>(pos-1)))],tree[now].son[1^(1&(x>>(pos-1)))],x,pos-1)+(1<<(pos-1)):
			query(tree[pre].son[1&(x>>(pos-1))],tree[now].son[1&(x>>(pos-1))],x,pos-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		sum[i]=sum[i-1]^a[i];
	root[0]=++k;
	for(int i=0;i<=n;i++)
		root[i+1]=update(root[i],sum[i],25);
	for(int i=1,l,r,x;i<=m;i++){
		char opt;
		scanf("\n%c",&opt);
		if(opt=='A')scanf("%d",&x),sum[n+1]=sum[n]^x,root[n+2]=update(root[n+1],sum[n+1],25),n++;
		else{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",query(root[l-1],root[r],x^sum[n],25));
		}
	}
	return 0;
}