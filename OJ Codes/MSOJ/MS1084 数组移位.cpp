#include<cstdio>
using namespace std;
const int N=1000;
int a[N+10];
int x,k;
int main()
{
	scanf("%d",&x);
	int i=0;
	while(x!=0)
	{	
		i++;
		a[i]=x;
		scanf("%d",&x);
	}
	k=i;
	for(;i>=1;i--)
	{
		a[i+1]=a[i];
	}
	a[1]=a[k+1];
	
	for(int i=1;i<=k;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}