#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,m,k,block,l,r,sum;
int a[maxn];
struct node{
	int l,r,id;
}q[maxn];
int book[maxn],ans[maxn];
bool cmp(node a,node b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	else
	return a.l/block<b.l/block;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	block=sqrt(n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&q[i].l,&q[i].r),
	q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)
		{
			sum-=book[a[l]]*2-1;
			book[a[l]]--;
			l++;
		}
		while(l>q[i].l)
		{
			sum+=book[a[l-1]]*2+1;
			book[a[l-1]]++;
			l--;
		}
		while(r<q[i].r)
		{
			sum+=book[a[r+1]]*2+1;
			book[a[r+1]]++;
			r++;
		}
		while(r>q[i].r)
		{
			sum-=book[a[r]]*2-1;
			book[a[r]]--;
			r--;
		}
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]-1);
	return 0;
}
