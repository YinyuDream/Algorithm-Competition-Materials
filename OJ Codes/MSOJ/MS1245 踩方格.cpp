#include<cstdio>
using namespace std;
int n,ans;
bool a[200][200];
int dx[3]={0,-1,0};
int dy[3]={-1,0,1};
void dfs(int x,int y,int k)
{
	if(k==n+1)
	{
		ans++;return ;
	}
	else if(a[x][y-1]!=0&&a[x-1][y]!=0&&a[x][y+1]!=0&&k!=n+1)return ;
	else
	{
		for(int i=0;i<=2;i++)
		{
			int ddx=x+dx[i],ddy=y+dy[i];
			if(a[ddx][ddy]==0)
			{
				a[ddx][ddy]=1;
				dfs(ddx,ddy,k+1);
				a[ddx][ddy]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	a[100][100]=1;
	dfs(100,100,1);
	printf("%d",ans);
	return 0;
 } 
