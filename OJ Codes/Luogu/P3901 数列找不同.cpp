#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,m,block,l=1,r,sum;
int a[maxn],book[maxn],ans[maxn];
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
int main()
{
	scanf("%d%d",&n,&m);
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
			book[a[l]]--;
			if(book[a[l]]==0)sum--;
			l++;
		}
		while(l>q[i].l)
		{
			book[a[l-1]]++;
			if(book[a[l-1]]==1)sum++;
			l--;
		}
		while(r<q[i].r)
		{
			book[a[r+1]]++;
			if(book[a[r+1]]==1)sum++;
			r++;
		}
		while(r>q[i].r)
		{
			book[a[r]]--;
			if(book[a[r]]==0)sum--;
			r--;
		}
		//printf("%d   %d   %d   %d\n",l,r,q[i].id,sum);
		if(sum==q[i].r-q[i].l+1)
		ans[q[i].id]=1;
		else
		ans[q[i].id]=0;
	}
	for(int i=1;i<=m;i++)
	printf("%s\n",ans[i]==1?"Yes":"No");
	return 0;
}
