#include<cstdio>
using namespace std;
int m,n,cnt,k;
int a[1000];
void dfs(int x)
{
	if(x==0)
	{
		cnt++;return ;
	}
	else
	{
		for(int i=a[k];i<=x;i++)
		{
			if(k+1>n)break;
			k++;
			a[k]=i;
			dfs(x-i);
			k--;
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		k=1;
        a[1]=i;
		dfs(m-i);
	}
	printf("%d",cnt); 
	return 0;
}
