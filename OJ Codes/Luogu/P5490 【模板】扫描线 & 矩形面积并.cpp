#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,b[maxn],pos[maxn];
long long ans;
struct square{
	int a1,b1,a2,b2;
}a[maxn];
struct segment{
	l,r,y,opt;
}z[maxn];
struct node{
	int l,r,lazy,sum;
}teee[maxn];
bool cmp(segment _a,segment _b)
{
	return _a.y<_b.y;
}
void lsh()
{
	for(int i=1;i<=n;i++)
		b[i]=a[i].a1,b[i+n]=a[i].a2;
	sort(b+1,b+n*2+1);
	int cnt=unique(b+1,b+n*2+1)-b-1;
	for(int i=1;i<=n;i++){
		int t1=lower_bound(b+1,b+cnt+1,a[i].a1)-b,
			t2=lower_bound(b+1,b+cnt+1,a[i].a2)-b;
		pos[t1]=a[i].a1,pos[t2]=a[i].a2,a[i].a1=t1,a[i].a2=t2;
	}
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==l&&tree[id].r==r)return ;
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&a[i].a1,&a[i].b1,&a[i].a2,&a[i].b2);
	build(1,1,lsh());
	for(int i=1;i<=n;i++)
		z[i*2-1]={a[i].a1,a[i].a2,a[i].b1,1},
		z[i*2]={a[i].a1,a[i].a2,a[i].b2,-1};
	sort(z+1,z+n*2+1,cmp);
	for(int i=1;i<=n*2;i++)
	{
		ans+=query()*(z[i].y-z[i-1].y);
		update();
	}
	printf("%lld\n",ans);
	return 0;
}
