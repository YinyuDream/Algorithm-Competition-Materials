#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn+10];
int cut;
int main()
{
	for(int i=1;1;i++)
	{
		scanf("%d",&a[i]);
		cut++;
		if(a[i]==0)break;
	}
	for(int j=cut-1;j>=1;j--)
	{
		printf("%d ",a[j]);
	}
	return 0;
}