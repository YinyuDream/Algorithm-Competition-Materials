#include<cstdio>
using namespace std;
int n,cnt;
bool a[20];
void dfs(int x)
{
	if(x==n+1)
	{
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
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
	printf("%d",cnt);
	return 0;
} 
