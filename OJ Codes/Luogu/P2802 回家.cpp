#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e2+10;
int n,m,stx,sty,edx,edy,ans=0x7f7f7f7f;
int mapp[maxn][maxn];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int book[maxn][maxn];
void dfs(int x,int y,int blood,int step)
{
	if(blood==0)return ;
	if(x==edx&&y==edy){
		ans=min(ans,step);
		return ;
	}
	for(int i=0;i<=3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m||mapp[nx][ny]==0)continue;
		if(book[nx][ny]<=1&&mapp[nx][ny]==1)book[nx][ny]++,dfs(nx,ny,blood-1,step+1),book[nx][ny]--;
		if(book[nx][ny]==0&&mapp[nx][ny]==4&&blood>1)book[nx][ny]++,dfs(nx,ny,6,step+1),book[nx][ny]--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mapp[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mapp[i][j]==2)stx=i,sty=j;
			else if(mapp[i][j]==3)edx=i,edy=j,mapp[i][j]=1;
			else continue;
	dfs(stx,sty,6,0);
	if(ans!=0x7f7f7f7f)printf("%d",ans);
	else printf("-1");
	return 0;
}
