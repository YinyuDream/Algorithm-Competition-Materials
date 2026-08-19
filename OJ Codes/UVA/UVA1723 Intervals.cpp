#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int T,w;
struct seg{
	int l,r,cnt;
}e[maxn];
bool cmp(seg a,seg b)
{
	return a.r<b.r;
}
struct node{
	int l,r,len,sum,lazy;
}tree[4*maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	tree[id].lazy=tree[id].sum=0;
	tree[id].len=r-l+1;
	if(tree[id].l==tree[id].r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id].lazy;
	tree[id*2].sum=tree[id*2].r-tree[id*2].l+1;
	tree[id*2+1].lazy=tree[id].lazy;
	tree[id*2+1].sum=tree[id*2+1].r-tree[id*2+1].l+1;
	tree[id].lazy=0;
}
void update(int id,int l,int r)
{
	if(tree[id].lazy)pushdown(id);
	if(tree[id].l>r||tree[id].r<l||w<=0||tree[id].sum==tree[id].len)return ;
	else if(tree[id].l>=l&&tree[id].r<=r&&w>=tree[id].len-tree[id].sum)
	{
		w-=tree[id].len-tree[id].sum;
		tree[id].sum=tree[id].len;
		tree[id].lazy=1;
		return ;
	}
	else update(id*2+1,l,r),update(id*2,l,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	return tree[id].sum;
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return query(id*2,l,mid)+query(id*2+1,mid+1,r);
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		int n;w=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].cnt);
		sort(e+1,e+n+1,cmp);
		build(1,1,e[n].r+1);
		for(int i=1;i<=n;i++)
		{
			w=e[i].cnt-query(1,e[i].l,e[i].r);
			update(1,e[i].l,e[i].r);
		}
		if(T!=1)
		printf("%d\n",tree[1].sum);
		else printf("%d",tree[1].sum);
	}
	return 0;
}
