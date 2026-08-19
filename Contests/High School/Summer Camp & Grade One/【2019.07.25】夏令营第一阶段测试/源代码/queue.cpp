#include<cstdio>
using namespace std;
int n,cnt;
int temp;
int a[100010];
void dfk(int x)
{
	if(a[x+1]==a[x])return ;
	else
	{
		int temp=a[x+1]-a[x];
		if(temp>=5)temp=5;
		else if(temp>=2)temp=2;
		else if(temp==1)temp=1;
		else;
		for(int j=1;j<=n;j++)
		{
			if(j==x+1)continue;
			a[j]+=temp;
			
		}
		cnt++;
		dfk(x);
	}	
}
void dfs()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
		{
			dfk(i);
		}
	}
}
int	main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		bool bo=0;
		for(int j=n-1;j>=i;j--)
		{
			if(a[j]>a[j+1])
			{
			 temp=a[j];a[j]=a[j+1];a[j+1]=temp;bo==1;
			}
			if(bo==0)break;
		}
	}
	dfs();
	printf("%d",cnt);
	return 0;
}
