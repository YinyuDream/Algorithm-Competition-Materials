#include<cstdio>
using namespace std;

const int maxn=100;
int n,m,s;
int a[maxn][maxn];
int b[maxn*maxn][2];
int dx[4]={0,-1,0,1};//hang
int dy[4]={-1,0,1,0};//lie
int x1,x2,y1,y2;
bool ca;

void pt()
{
	for(int i=0;i<s;i++)printf("(%d,%d)->",b[i][0],b[i][1]);
	printf("(%d,%d)\n",b[s][0],b[s][1]);
	ca=1;
}
void dfs(int x,int y)
{
	if(x==x2&&y==y2)
	{
		pt();
		return ;
	}
	else
	{
		int ddx=0,ddy=0;
		for(int i=0;i<=3;i++)
		{
			ddx=x+dx[i];ddy=y+dy[i];
			if(a[ddx][ddy]==1)
			{
				s++;
				a[ddx][ddy]=0;
				b[s][0]=ddx;b[s][1]=ddy;
				dfs(ddx,ddy);
				a[ddx][ddy]=1;
				s--;
						
			}
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	a[1][1]=0;
	b[0][1]=1;b[0][0]=1;
	dfs(x1,y1);		
	if(ca==0)printf("-1");
	return 0;
}
