#include<cstdio>
using namespace std;
const int maxn=110;
int n,m,minx=1e8,s;
int a[maxn][maxn];
int x1,x2,y1,y2;
int dx[4]={0,1,0,-1};//hang
int dy[4]={1,0,-1,0};//lie
bool ca;
int lent[maxn][maxn];
int ans[maxn*maxn];
void dfs(int x,int y)
{
	lent[x][y]=s;
	if(x==x2&&y==y2)
	{
		ca=1;
		if(s<=minx)
		{
			minx=s;
			ans[minx]++;
		}
		 
		return ;
	}
	int ddx=0,ddy=0;
	for(int i=0;i<=3;i++)
	{
		ddx=x+dx[i];ddy=y+dy[i];
		if(a[ddx][ddy]==0&&s+1<=lent[ddx][ddy])
		{
			s++;
			a[ddx][ddy]=1;
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
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	a[x1][y1]=1;lent[x1][y1]=0;
	dfs(x1,y1);		
	if(ca==0)printf("-1");
	else
	{
		printf("%d\n",ans[minx]);
	} 
	return 0;
}