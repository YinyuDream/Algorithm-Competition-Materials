#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=6;
int t,mapp[N][N],qx,qy,book;
char a[N][N];
const int nextn[8][2]={
	{1,2},
	{1,-2},
	{2,1},
	{2,-1},
	{-1,2},
	{-1,-2},
	{-2,1},
	{-2,-1}
};
const int map_std[N][N]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,-1,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
inline int judge()
{
	int cnt=0;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			if(mapp[i][j]!=map_std[i][j])cnt++;
	return cnt>1?cnt-1:0;
}
inline void init()
{
	book=qx=qy=0;
	memset(a,0,sizeof a);
	memset(mapp,0,sizeof mapp);
	for(int i=1;i<N;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			mapp[i][j]=a[i][j]-'0';
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			if(a[i][j]=='*')
			{
				mapp[i][j]=-1;
				qx=i,qy=j;
				break;
			}
}
void dfs(int x,int y,int step,int deep)
{
	int Judge=judge();
	if(book||step>deep||Judge+step>deep)return ;
	if(Judge==0){
		book=1;return ;
	}
	for(int i=0;i<=7;i++)
	{
		int nx=nextn[i][0]+x,ny=nextn[i][1]+y;
		if(nx<=5&&ny<=5&&nx>=1&&ny>=1)
			swap(mapp[x][y],mapp[nx][ny]),
			dfs(nx,ny,step+1,deep),
			swap(mapp[x][y],mapp[nx][ny]);
	}
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		init();
		for(int j=1;j<=15;j++)
		{
			dfs(qx,qy,0,j);
			if(book){
				printf("%d\n",j);
				break;
			}
		}
		if(!book)printf("-1\n");
	}
	return 0;
}
