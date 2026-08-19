#include<cstdio>
using namespace std;
int n;
int a[10010];
int main()
{
	scanf("%d",&n);
	a[1]=1;a[2]=2;
	for(int i=3;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-2])%10000007; 
	}
	printf("%d",a[n]);
	return 0;
}