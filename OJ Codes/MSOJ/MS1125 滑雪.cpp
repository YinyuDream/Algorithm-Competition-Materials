#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,minn=10000,ans=-1;
int a[110][110];
int l[110][110];
int dx[4]{0,0,1,-1};
int dy[4]{1,-1,0,0};
bool w[110][110];
int dfs(int x,int y)	
{		
	int ddx,ddy;
	
	for(int i=0;i<=3;i++)
	{
		ddx=x+dx[i];ddy=y+dy[i];
		if(a[ddx][ddy]<a[x][y] && a[ddx][ddy]>0)
		{
		 if(l[x][y]<dfs(ddx,ddy))l[x][y]=dfs(ddx,ddy);
		}
	}
	int bo=0;
	for(int i=0;i<=3;i++)
	{
		ddx=x+dx[i];ddy=y+dy[i];
		if(a[ddx][ddy]>=a[x][y] || a[ddx][ddy]==0)
		{
		 bo++;
		}
	}
	if(bo!=4&&w[x][y]==0)
	{
		l[x][y]++;
		w[x][y]=1;	
	}
if(l[x][y]>1)
	{
		return l[x][y];
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			l[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(l[i][j]==1)
			{
				dfs(i,j);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)ans=max(ans,l[i][j]);
	}
	printf("%d",ans);
	return 0;
}
