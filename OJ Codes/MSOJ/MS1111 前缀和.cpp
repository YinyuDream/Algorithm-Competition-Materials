#include<cstdio>
using namespace std;
int n,m,x;
int a;
long long sum[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum[i]=a+sum[i-1]; 
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		printf("%lld",sum[x]);
		printf("\n");
	}
	return 0;
}
