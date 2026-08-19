#include<cstdio>
using namespace std;
int m,n,k,cnt;
int a[10000];
void kfs(int x)
{
	
	if(x==1)cnt++;
	else{
		for(int j=a[k];j<=x;j++)
	{
		if(x%j==0)
		{
		k++;
		a[k]=j;
		kfs(x/j);
		k--;
		}
	}
	}
}
int main()
{
	scanf("%d",&m);
	for(int j=1;j<=m;j++)
	{
		cnt=0;
		scanf("%d",&n);
		for(int i=2;i<=n;i++)
		{
			if(n%i==0)
			{
			k=1;
			a[1]=i;
			kfs(n/i);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
