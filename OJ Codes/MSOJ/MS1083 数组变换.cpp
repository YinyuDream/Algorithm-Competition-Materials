#include<cstdio>
using namespace std;
int a[10000000];
int n,y,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&y,&x);
	y=y+1; 
	for(int i=n;i>=y;i--)
	{
		a[i+1]=a[i];
	}
	a[y]=x;
	for(int i=1;i<=n+1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
