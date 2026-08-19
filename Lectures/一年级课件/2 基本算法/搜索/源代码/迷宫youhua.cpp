#include<cstdio>

int n,a[110][110];
int book[110][110];
int minn=99999999;
int xy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int qx,qy,zx,zy;
bool flag=0;
int ans[110][110];
void dfs(int step,int x,int y)
{
	ans[x][y]=step;
	if(x==zx && y==zy)
	{
		flag=1;
		if(step<minn)minn=step;
		return;
	}
	//if(step>=minn)return;
	int x1,y1;
	for(int i=0;i<=3;i++)
	{
		x1=x+xy[i][0];y1=y+xy[i][1];
		if(x>=1 && x<=n && y>=1 && y<=n && book[x1][y1]==0 && a[x1][y1]==0 && step+1<ans[x1][y1])
		{
			book[x1][y1]=1;
			dfs(step+1,x1,y1);
			book[x1][y1]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),ans[i][j]=99999999;
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	book[qx][qy]=1;ans[qx][qy]=0;
	dfs(0,qx,qy);
	if(flag)	printf("%d\n",minn);
	else printf("-1");
	return 0;
}
