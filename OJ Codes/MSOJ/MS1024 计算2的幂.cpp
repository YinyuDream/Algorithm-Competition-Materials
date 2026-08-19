#include<cstdio>
using namespace std;
int n;
long long sum=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum=sum*2;
	}
	printf("%lld",sum);
	return 0;
}