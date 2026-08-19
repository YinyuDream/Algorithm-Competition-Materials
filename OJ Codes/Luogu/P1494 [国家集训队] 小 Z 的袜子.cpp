#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,block,l,r,sum;
int a[maxn];
struct node{
	int l,r,id;
}q[maxn];
struct Ans{
	int p,q;
}ans[maxn];
int book[maxn];
bool cmp(node a,node b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	else
	return a.l/block<b.l/block;
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
void work(int i)
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
}
signed main()
{
	//freopen("P1494_1.in","r",stdin);
	//freopen("ans.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	block=sqrt(n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%lld%lld",&q[i].l,&q[i].r),
	q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		work(i);
		ans[q[i].id].p=sum-1-(r-l+1);
		ans[q[i].id].q=(r-l+1)*(r-l);
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i].p){
			int t=gcd(ans[i].p,ans[i].q);
			printf("%lld/%lld\n",ans[i].p/t,ans[i].q/t);
		}else{
			puts("0/1");
		}
	}
	return 0;
}
