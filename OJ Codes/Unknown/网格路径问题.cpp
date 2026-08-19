#include<cstdio>
using namespace std;
int a[1010][1010];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		scanf("%d",&a[0][0]);
		if(a[0][0]==1)a[i][j]=-1;
		}
	}
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i][1]==-1)a[i][1]=0;
		else a[i][1]=a[i-1][1];
	}
	for(int j=2;j<=m;j++)
	{
		if(a[1][j]==-1)a[1][j]=0;
		else a[1][j]=a[1][j-1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
		if(a[i][j]==-1)a[i][j]=0;
		else a[i][j]=(a[i-1][j]+a[i][j-1])%123456; 
		}
	}
	printf("%d\n",a[n][m]);
	return 0;
}
