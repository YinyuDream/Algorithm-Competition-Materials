#include<cstdio>
using namespace std;
int a[100010];
int n,x,maxn;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
		if(maxn<x)maxn=x;
		 
	}
	for(int i=0;i<=maxn;i++)
	{
		while(a[i]>0)
		{
			printf("%d ",i);
			a[i]--;
		}
	}
	return 0;
}
