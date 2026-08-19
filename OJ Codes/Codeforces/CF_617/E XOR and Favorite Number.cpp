#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=3e6+10;
int n,m,k,block;
int a[maxn],sum[maxn],book[maxn],ans[maxn],l,r,cnt;
struct node{
	int l,r,id;
}q[maxn];
bool cmp(node a,node b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	else
	return a.l/block<b.l/block;
}
void update(int x,int opt)
{
	if(opt==1)
	cnt+=book[sum[x]^k],book[sum[x]]++;
	else
	book[sum[x]]--,cnt-=book[sum[x]^k];
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	block=sqrt(n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%lld%lld",&q[i].l,&q[i].r),
	q[i].id=i,q[i].l--;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]^a[i];
	book[0]=1;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)update(l++,2);
		while(l>q[i].l)update(--l,1);
		while(r<q[i].r)update(++r,1);
		while(r>q[i].r)update(r--,2);
		ans[q[i].id]=cnt;
	}
	for(int i=1;i<=m;i++)
	printf("%lld\n",ans[i]);
}
