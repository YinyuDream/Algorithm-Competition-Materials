#include<cstdio>
using namespace std;
const int maxn=100;
int n,m,minx=1000000,s;
int a[maxn][maxn];
int x1,x2,y1,y2;
int dx[4]={0,1,0,-1};//hang
int dy[4]={1,0,-1,0};//lie
bool ca;
int lent[maxn][maxn];
int ans[maxn*maxn][2];
int ttemp[maxn*maxn][2];
void dfs(int x,int y)
{
	lent[x][y]=s;
	if(x==n&&y==m)
	{
		ca=1;
		if(s<minx)
		{
			minx=s;
			for(int i=1;i<=minx;i++)
			{
				ans[i][0]=ttemp[i][0];ans[i][1]=ttemp[i][1];
			}		
		} 
		return ;
	}
	int ddx=0,ddy=0;
	for(int i=0;i<=3;i++)
	{
		ddx=x+dx[i];ddy=y+dy[i];
		if(a[ddx][ddy]==0&&s+1<lent[ddx][ddy])
		{
			s++;
			a[ddx][ddy]=1;
			ttemp[s][0]=ddx;ttemp[s][1]=ddy;
			dfs(ddx,ddy);
			a[ddx][ddy]=0;
			s--;					
		}
	}
}
int main()
{
	for(int i=0;i<=maxn-1;i++)
	{
		for(int j=0;j<=maxn-1;j++)a[i][j]=1;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		scanf("%d",&a[i][j]);
		lent[i][j]=1e9;
		}
	}
	a[1][1]=1;lent[1][1]=0;ans[0][0]=ans[0][1]=1; 
	dfs(1,1);		
	if(ca==0)printf("-1");
	else
	{
		printf("%d\n",minx);
		for(int i=0;i<=minx;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	} 
	return 0;
}