#include<cstdio>
using namespace std;
int n,cnt;
int a[20],b[20];
void dfs(int x)
{
	if(x==n+1)
	{
		cnt++;
		if(cnt>=2)printf("\n");					
		for(int j=1;j<=n;j++)printf("%5d",b[j]);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			b[x]=i;
			dfs(x+1);
			a[i]=0;	
		} 
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
} 
