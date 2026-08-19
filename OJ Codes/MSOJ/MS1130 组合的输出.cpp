#include<cstdio>
using namespace std;
int n,cnt,r;
int a[30],b[30];
void dfs(int x)
{
	if(x==r+1)
	{
		cnt++;
		if(cnt>=2)printf("\n");					
		for(int j=1;j<=r;j++)printf("%3d",b[j]);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{	
			a[i]=1;
			b[x]=i;	
			if(b[x-1]>b[x])
			{
				a[i]=0;
				continue;
			}
			dfs(x+1);	
			a[i]=0;	
		} 
	
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	dfs(1);
	return 0;
} 
