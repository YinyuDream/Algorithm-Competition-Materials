#include<cstdio>
using namespace std;
int n;
int a[100010];
int main()
{
	scanf("%d",&n);
	a[n+1]=10000000;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}
