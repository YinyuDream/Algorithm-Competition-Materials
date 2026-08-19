#include<cstdio>
using namespace std;
int an[100000+10];
int n,x,a;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&an[i]);
	}
	scanf("%d",&x);
	an[n+1]=10000000;
	for(int i=1;i<=n+1;i++)
	{
		if(an[i]>x){
			a=i;break;
		}
	}
	for(int j=n+1;j>=a;j--)
	{
		an[j+1]=an[j];
	}
	an[a]=x;
	for(int i=1;i<=n+1;i++)
	{
		printf("%d ",an[i]);
	}
	return 0;
}
