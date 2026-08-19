#include<cstdio>
using namespace std;
int n,m,cnt;
int dx[4]={-2,-1,1,2};
int dy[4]={1,2,2,1};
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		cnt++;return;
	}
	for(int i=0;i<=3;i++)
	{
		int ddx=x+dx[i],ddy=y+dy[i];
		if(ddx<=n&&ddy<=m&&ddx>=0)
		{
			dfs(ddx,ddy);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(0,0);
	printf("%d",cnt);
	return 0;
}