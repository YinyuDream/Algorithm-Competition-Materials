#include<cstdio>
using namespace std;
int cnt=0;
int k[10][10];
bool a[10][10];//行 
bool b[10][10];//列 
bool c[10][10];//小格
void print()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)printf("%d ",k[i][j]);
		printf("\n");
	}
	cnt++;
	return ;
}
void dfs(int x,int y)
{
	if(k[x][y]!=0)
	{
		if(x==9&&y==9)print();
		else if(y==9) dfs(x+1,1);
		else dfs(x,y+1);
	}
	else
	{
		for(int m=1;m<=9;m++)
		{
			if(a[x][m]==0&&b[y][m]==0&&c[(x-1)/3+(y-1)/3*3+1][m]==0)
			{
				a[x][m]=1;b[y][m]=1;c[(x-1)/3+(y-1)/3*3+1][m]=1;k[x][y]=m;
				if(x==9&&y==9)print();
				else if(y==9&&x!=9)dfs(x+1,1);
				else if(y!=9)dfs(x,y+1);
				else ;
				a[x][m]=0;b[y][m]=0;c[(x-1)/3+(y-1)/3*3+1][m]=0;k[x][y]=0;
			}
		} 
	}	
} 
int main()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&k[i][j]);
			a[i][k[i][j]]=1;
			b[j][k[i][j]]=1;
			c[(i-1)/3+(j-1)/3*3+1][k[i][j]]=1;
		} 
	}
	dfs(1,1);
	return 0;
} 