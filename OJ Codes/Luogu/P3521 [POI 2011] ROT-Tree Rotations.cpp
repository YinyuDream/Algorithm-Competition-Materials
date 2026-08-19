#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,cnt;
long long t1,t2,ans;
struct node{
	int l,r;
	long long size;
}tree[30*maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
int build(int l,int r,int val)
{
	int k=++cnt;
	if(l==r){
		tree[k].size=1;
		return k;
	}
	int mid=(l+r)/2;
	if(val<=mid)
	tree[k].l=build(l,mid,val);
	else
	tree[k].r=build(mid+1,r,val);
	tree[k].size=tree[tree[k].l].size+tree[tree[k].r].size;
	return k;
}
int merge(int p,int q,int l,int r)
{
	if(!p||!q)
	return p+q;
	if(l==r){
		tree[p].size+=tree[q].size;
		return p;
	}
	t1+=tree[tree[p].r].size*tree[tree[q].l].size;
	t2+=tree[tree[p].l].size*tree[tree[q].r].size;
	int mid=(l+r)/2;
	tree[p].l=merge(tree[p].l,tree[q].l,l,mid);
	tree[p].r=merge(tree[p].r,tree[q].r,mid+1,r);
	tree[p].size=tree[tree[p].l].size+tree[tree[p].r].size;
	return p;
}
int dfs()
{
	int k=read(),pos;
	if(k==0)
	{
		int lson=dfs();
		int rson=dfs();
		t1=t2=0;
		pos=merge(lson,rson,1,n);
		ans+=min(t1,t2);
		return pos;
	}
	else
	return build(1,n,k);
}
int main()
{
	n=read();
	dfs();
	printf("%lld",ans);
	return 0;
}