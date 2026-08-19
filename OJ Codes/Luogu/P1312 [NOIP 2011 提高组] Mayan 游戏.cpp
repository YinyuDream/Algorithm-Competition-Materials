#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=7,M=5;
int max_step;
struct node{
	int x,y,opt;
}c[N];
int a[N][N][N];
int read(){
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x;
}
void copy(int step)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			a[step][i][j]=a[step-1][i][j];	 
}
bool check(int step)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(a[step][i][j])return false;
	return true;
}
void down(int step)
{
	for(int i=1;i<N;i++)
		for(int j=0;j<M;j++)
			if(a[step][i-1][j]==0)
			{
				int k=i;
				while(a[step][k-1][j]==0)
				a[step][k-1][j]=a[step][k][j],a[step][k][j]=0,k--;
			}
			
}
bool check_maps(int step)
{
	for(int i=1;i<N-1;i++)
		for(int j=1;j<M-1;j++)
			if((a[step][i][j]!=0&&a[step][i-1][j]==a[step][i][j]&&a[step][i][j]==a[step][i+1][j])||
			   (a[step][i][j]!=0&&a[step][i][j-1]==a[step][i][j]&&a[step][i][j]==a[step][i][j+1]))
				return true;
	return false;
} 
void update(int step)
{
	int flag[N][M];
	memset(flag,0,sizeof flag);
	for(int i=1;i<N-1;i++)
		for(int j=1;j<M-1;j++)
		{
			
			if(a[step][i][j]!=0&&a[step][i-1][j]==a[step][i][j]&&a[step][i][j]==a[step][i+1][j])
			flag[i-1][j]=flag[i][j]=flag[i+1][j]=1;
			if(a[step][i][j]!=0&&a[step][i][j-1]==a[step][i][j]&&a[step][i][j]==a[step][i][j+1])
			flag[i][j-1]=flag[i][j]=flag[i][j+1]=1;
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(flag[i][j]==1)
				a[step][i][j]=0; 
}
void change(int x,int y,int opt,int step)
{
	if(opt==0)swap(a[step][x][y-1],a[step][x][y]);
	else swap(a[step][x][y+1],a[step][x][y]);
	down(step);
	//while(check_maps(step)){
		update(step);
		down(step);
	//}
}
void dfs(int step)
{
	if(step==max_step+1){
		if(check(step))
		{
			for(int i=1;i<step;i++)
			printf("%d %d %d\n",c[i].x,c[i].y,c[i].opt);
			exit(0);
		}
		return ;
	}
	for(int i=0;i<N;i++)
		for(int j=1;j<M;j++)
		{
			copy(step);
			if(j+1<M)
			{
				change(i,j,1,step);
				c[step]={i,j,1};
				dfs(step+1);
			}
			copy(step);
			if(j-1>=0)
			{
				change(i,j,0,step);
				c[step]={i,j,0};
				dfs(step+1);
			}
		}
}
int main(){
	scanf("%d",&max_step);
	for(int i=0;i<M;i++)
	{
		int color,top=0;
		while((color=read())!=0)
		a[0][top++][i]=color;
	}
	dfs(1);
	puts("-1");
	return 0;
}
