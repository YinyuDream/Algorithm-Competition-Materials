#include<cstdio>
using namespace std;
const int maxn=30;
int n;
int a[maxn][maxn],ans[maxn];
bool book[maxn];
void print()
{
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
}
void dfs(int x,int y)
{
	if(x==n+1)print();
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0&&a[y][i]==1)
		{
			book[i]=1;
			ans[x]=i;
			dfs(x+1,i);
			book[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		book[i]=1;
		ans[1]=i;
		dfs(2,i);
		book[i]=0;
	}
	return 0;
}

