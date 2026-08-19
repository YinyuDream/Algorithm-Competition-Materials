#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int b[maxn],root[maxn],c[maxn];
struct Num{
	int val,id;
}a[maxn];
struct node{
	int l,r,size,val;
}tree[30*maxn];
bool cmp(Num a,Num b)
{
	return a.val<b.val;
}
bool cmp2(Num a,Num b)
{
	return a.id<b.id;
}
int lsh()
{
	int cnt=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].val!=a[i-1].val)
		{
			cnt++;
		}
		b[a[i].id]=cnt;
		//c[b[a[i].num]]=a[i].val;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
	a[b[i]].id=a[i].val;
	return cnt;
}
int build(int l,int r)
{
	int now=++k;
	if(l==r)
	return now;
	int mid=(l+r)/2;
	tree[now].l=build(l,mid);
	tree[now].r=build(mid+1,r);
	return now;
}
int update(int pre,int l,int r,int x)
{
	int now=++k;
	tree[now]=tree[pre];
	tree[now].size=tree[pre].size+1;
	if(l==r){
		//tree[now].val=x;
		return now;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	tree[now].l=update(tree[pre].l,l,mid,x);
	else
	tree[now].r=update(tree[pre].r,mid+1,r,x);
	return now;
}
int query(int pre,int now,int l,int r,int k)
{
	if(l==r)
	return l;
	int tmp=tree[tree[now].l].size-tree[tree[pre].l].size,mid=(l+r)/2;
	//printf("%d   %d   %d   %d\n",l,r,k,tree[now].size);
	if(k<=tmp)
	return query(tree[pre].l,tree[now].l,l,mid,k);
	else
	return query(tree[pre].r,tree[now].r,mid+1,r,k-tmp);
}
int main()
{
	a[0].val=-0x7f7f7f7f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].val),a[i].id=i;
	int N=lsh();
	root[0]=build(1,N);
	for(int i=1;i<=n;i++)
	root[i]=update(root[i-1],1,N,b[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",a[query(root[l-1],root[r],1,N,k)].id);
	}
	return 0;
}