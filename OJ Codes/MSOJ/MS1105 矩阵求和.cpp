#include<cstdio>
using namespace std;
int n,m;
long long sum;
int a[1000][1000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			sum=sum+a[i][j]; 
		} 
	}
	printf("%lld",sum);
	return 0;
}
