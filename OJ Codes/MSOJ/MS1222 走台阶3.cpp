#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int a[100010];
int f(int k)
{
	int sum=0;
	for(int j=1;j<=m;j++)sum=sum+a[k-j];
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		a[i]=pow(2,i-1);
	}
	for(int i=m+1;i<=n;i++)
	{
		
		a[i]=f(i)%100003;
	}
	printf("%d",a[n]);
	return 0;
}
