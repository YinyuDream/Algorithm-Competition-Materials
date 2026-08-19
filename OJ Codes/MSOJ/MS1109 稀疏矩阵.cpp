#include<cstdio>
using namespace std;
int n,m;
int a[100][100];
bool bo=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		if(a[i][j]!=0)
		{
			printf("%d %d %d",i,j,a[i][j]);
			printf("\n");
			bo=1;
		}
	}
	if(bo==0)printf("0");
	return 0;
}
