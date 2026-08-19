#include<cstdio>
using namespace std;
int n;
double a[1010];
int main()
{
	scanf("%d",&n);
	a[1]=1;a[2]=1;
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
		printf("%.0f\n",a[n]);
	 
	return 0;
}
