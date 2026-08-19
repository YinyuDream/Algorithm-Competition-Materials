#include<cstdio>
using namespace std;
int n;
long long a[60][60];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i][1]=1;
	for(int i=1;i<=n;i++)a[i][i]=1;
	for(int i=3;i<=n;i++)
	{
		for(int j=2;j<i;j++)a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)printf("%lld ",a[i][j]);
		printf("\n");
	}
	return 0;
}
