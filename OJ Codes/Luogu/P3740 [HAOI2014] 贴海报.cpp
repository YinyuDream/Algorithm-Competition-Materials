#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=4e6+10;
int n,m,ans;
int book[maxn],l[maxn],r[maxn],a[maxn],b[maxn];
struct node{
	int l,r,lazy;
}tree[maxn];
int lsh()
{
	for(int i=1;i<=m;i++)
		a[i]=l[i],a[i+m]=r[i];
	for(int i=1;i<=m*2;i++)
		b[i]=a[i];
	sort(b+1,b+m*2+1);
	int cnt=unique(b+1,b+m*2+1)-b-1;
	for(int i=cnt;i>=2;i--)
		if(b[i-1]+1!=b[i])
			b[++cnt]=b[i-1]+1;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=m;i++)
		l[i]=lower_bound(b+1,b+cnt+1,l[i])-b,
		r[i]=lower_bound(b+1,b+cnt+1,r[i])-b;
	return cnt+1;
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id*2+1].lazy=tree[id].lazy;
	tree[id].lazy=0;
}
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(tree[id].l==tree[id].r)return;
    int mid=(tree[id].l+tree[id].r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void update(int id,int l,int r,int c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].lazy=c;
		return ;
	}
	if(tree[id].lazy)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
}
void query(int id)
{
	if(tree[id].lazy){
		book[tree[id].lazy]=1;
		return ;
	}
	if(tree[id].l==tree[id].r)return ;
	query(id*2),query(id*2+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]);
	build(1,1,lsh());
	for(int i=1;i<=m;i++)
		update(1,l[i],r[i],i);
	query(1);
	for(int i=1;i<=m;i++)
		if(book[i])
			ans++;
	printf("%d",ans);
	return 0;
}
