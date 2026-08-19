#include<cstdio>
using namespace std;

const int maxn=200000+10;
int n;
int a[maxn],sum[maxn];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}
	sum[1]=a[1];
	sum[0]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(sum[i-1]>0)sum[i]=sum[i-1]+a[i];
		else sum[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>sum[0])sum[0]=sum[i];
	}
	printf("%d\n",sum[0]);
	return 0;
}
