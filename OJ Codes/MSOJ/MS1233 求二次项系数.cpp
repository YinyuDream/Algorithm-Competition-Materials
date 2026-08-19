#include<cstdio>
using namespace std;
int n,m;
long long a[60][60];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m+1;i++)a[i][1]=1;
	for(int i=1;i<=n+m+1;i++)a[i][i]=1;
	for(int i=3;i<=n+m+1;i++)
	{
		for(int j=2;j<i;j++)a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	printf("%lld ",a[m+n+1][m+1]);
	return 0;
}
