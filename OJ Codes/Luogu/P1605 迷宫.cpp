#include<cstdio>
using namespace std;

const int maxn=110;
int n,m,t,s,cnt;
int a[maxn][maxn];
int b[maxn][maxn];
int x1,x2,y1,y2;
int dx[4]={0,1,0,-1};//hang
int dy[4]={1,0,-1,0};//lie

void dfs(int x,int y)
{
	if(x==x2&&y==y2)
	{
		cnt++;
		return;
	}
	int ddx=0,ddy=0;
	for(int i=0;i<=3;i++)
	{
		ddx=x+dx[i];ddy=y+dy[i];
		if(a[ddx][ddy]==0 && ddx>0 && ddy>0 && ddx<=n && ddy<=m && b[ddx][ddy]==0)
		{
			b[ddx][ddy]=1;
			dfs(ddx,ddy);
			b[ddx][ddy]=0;					
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int t1,t2;
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&t1,&t2);
		a[t1][t2]=1;	
	}
	a[x1][y1]=1;
	dfs(x1,y1);
	printf("%d",cnt);
	return 0;
}
