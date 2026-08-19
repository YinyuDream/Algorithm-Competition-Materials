#include<cstdio>
using namespace std;
int n,m;
int a[3000][3000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)a[i][i]=a[i][i]+m;
	for(int i=n;i>=1;i--)a[i][n-i+1]=a[i][n-i+1]+m;
	if(n%2==1)a[(1+n)/2][(1+n)/2]=a[(1+n)/2][(1+n)/2]-m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
		printf("\n");
	}
}
