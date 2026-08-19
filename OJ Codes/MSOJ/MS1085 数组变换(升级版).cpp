#include<cstdio>
using namespace std;
const int maxn=10000;
int a[maxn+10];
int n,x,c;
bool bo=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i++)
	{
		if(x==a[i])
		{
		bo=1;
			for(int j=i;j<=n-1;j++)
			{
				a[j]=a[j+1];
			}
			for(int j=1;j<=n-1;j++)
			{
				printf("%d ",a[j]);
			}
		break;		
		}
		
	}
	if(bo==0)
	{
		
		for(int i=1;i<=n;i++)
		{
			if(a[n]<x)
			{
				a[n+1]=x;
				bo=1;
				for(int k=1;k<=n+1;k++)
				{
					printf("%d ",a[k]);
				}
				break;
			}
			if(a[i]>x)
			{
				c=i;	
				break;
			}	
		}
		for(int j=n;j>=c;j--)
		{
			a[j+1]=a[j];
		}
		a[c]=x;
		if(bo==0)
		{
			for(int j=1;j<=n+1;j++)
			{
				printf("%d ",a[j]);
			}	
		}
	}
	return 0;
}