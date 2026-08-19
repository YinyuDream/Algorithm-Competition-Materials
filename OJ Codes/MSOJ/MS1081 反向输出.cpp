#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn+10];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=n;j>=1;j--)
	{
		printf("%d ",a[j]);
	}
	return 0;
}