#include<cstdio>
using namespace std;
int m,n,cnt;
char mapp[1010][1010];
bool a[1010][1010]; 
int dx[4]{0,0,1,-1};
int dy[4]{1,-1,0,0};
void dfs(int x,int y)
{
	int x1;int y1;
	for(int i=0;i<=3;i++)
	{
		x1=x+dx[i];y1=y+dy[i];
		if(a[x1][y1]==1)
		{
		a[x1][y1]=0;
		dfs(x1,y1);
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
		scanf(" %c",&mapp[i][j]);
		a[i][j]=mapp[i][j]-'0';
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				cnt++;
				a[i][j]=0;
				dfs(i,j);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}