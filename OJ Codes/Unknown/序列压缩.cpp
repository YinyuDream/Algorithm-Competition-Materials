#include<cstdio>
using namespace std;
int n,cnt,k,c;
int a[100010];
int sum; 
int main()
{
	scanf("%d",&n);
	k=n;
	a[n+1]=10000000;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt=0;
			c=c+1;
			for(int j=i;j<=n;j++)
			{
				sum=sum+1;
				cnt=cnt+1;
				if(a[j]<a[j+1])break;
			}
			for(int j=i;j<=n;j++)
			{
				a[j]=a[j+cnt-1];
			}
		}
		if(cnt!=0)n=n-cnt+1;
	}
	sum=sum-c;
	for(int i=1;i<=k-sum;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
