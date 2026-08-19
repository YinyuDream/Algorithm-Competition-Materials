#include<cstdio>
using namespace std;
int a[10];
int ans=0,x,y,max=0;
int main()
{
	for(int i=1;i<=7;i++)
	{
		scanf("%d%d",&x,&y);
		x=x+y;
		a[i]=x-8;
	}
	for(int i=7;i>=1;i--)
	{
		if(a[i]>=max&&a[i]>0){ans=i;max=a[i];}
	}
	printf("%d",ans);
	return 0;
}
