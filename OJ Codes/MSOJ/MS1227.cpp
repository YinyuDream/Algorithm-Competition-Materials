#include<cstdio>
using namespace std;
int n,temp;
int a[1001000];
int main()
{
	scanf("%d",&n);
	a[1]=1;a[2]=1;
	for(int i=3;i<=1001000;i++)
	{
		a[i]=(a[i-1]+a[i-2])%1000; 
		
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp); 
		printf("%d\n",a[temp]);
	} 
	return 0;
}