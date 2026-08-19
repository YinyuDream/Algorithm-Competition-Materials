#include<cstdio>
using namespace std;
int n;
int a[110][110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for (int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n"); 
	}
	return 0;
}
