#include<cstdio>
using namespace std;
int n,k;
int a[1000010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
	{
		if(k==a[i])
		{
			printf("%d",i);break;
		}
		if(k>a[i]&&k<a[i+1])
		{
			printf("%d %d",i,i+1);
		}
	}
	return 0;
}
