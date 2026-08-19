#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,t;
int a[maxn],root[maxn],help[maxn],b[maxn];
struct node{
	int l,r,size;
}tree[maxn*30];
int lsh()
{
	for(int i=1;i<=n;i++)
		help[i]=a[i];
	sort(help+1,help+n+1);
	int cnt=unique(help+1,help+n+1)-help-1;
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(help+1,help+cnt+1,a[i])-help;
		b[t]=a[i];
		a[i]=t;
	}
	return cnt;
}
int build(int l,int r){
	int now=++k;
	if(l==r)return now;
	int mid=(l+r)/2;
	tree[now].l=build(l,mid);
	tree[now].r=build(mid+1,r);
	return now;
}
int update(int pre,int l,int r,int c)
{
	int now=++k;
	if(l==r){
		tree[now].size=tree[pre].size+1;
		return now;
	}
	int mid=(l+r)/2;
	if(c<=mid)tree[now].l=update(tree[pre].l,l,mid,c),tree[now].r=tree[pre].r;
	else tree[now].r=update(tree[pre].r,mid+1,r,c),tree[now].l=tree[pre].l;
	tree[now].size=tree[tree[now].l].size+tree[tree[now].r].size;
	return now;
}
int query(int pre,int now,int l,int r,int kth)
{
	
	if(l==r)return l;
	int sz=tree[tree[now].l].size-tree[tree[pre].l].size,mid=(l+r)/2;
	if(kth<=sz)return query(tree[pre].l,tree[now].l,l,mid,kth);
	else return query(tree[pre].r,tree[now].r,mid+1,r,kth-sz);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	t=lsh();
	root[0]=build(1,t);
	for(int i=1;i<=n;i++)
		root[i]=update(root[i-1],1,t,a[i]);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),printf("%d\n",b[query(root[u-1],root[v],1,t,w)]);
	return 0;
}
