#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,cost1,cost2;
int mapp[25][100000+10];
int dp[25][100000+10][6];
bool visit[25][100000+10][6];
int ans=-0x7f7f7f7f,ansj,ansh;
inline bool cheak(int qx,int qy,int h)
{
	for(int i=1;i<h;i++)
		if(mapp[qx+i][qy+i]==-1)return false;
	return true;
}
inline int cost(int qx,int qy,int h)
{
	int sum=0;
	for(int i=0;i<h;i++)
	sum+=mapp[qx+i][qy+i];
	return sum;
}
int dfs(int x,int y,int k,int h,int limit)//x为列，y为行 
{
	if(x>=n+1)return 0;
	if(mapp[y][x]==-1)return -0x7f7f7f7f;
	if(visit[y][x][k])return dp[y][x][k];
	int maxx=-0x7f7f7f7f;
	if(y==1)
	{
		maxx=max(maxx,dfs(x+1,y,limit,h,limit)+mapp[y][x]);
		if(cheak(y,x,h)&&y+h<=m)maxx=max(maxx,dfs(x+h,y+h,limit-1,h,limit)+cost(y,x,h));
	}
	if(y>1)
	{
		maxx=max(maxx,dfs(x+1,y-1,k,h,limit)+mapp[y][x]);
		if(cheak(y,x,h)&&y+h<=m&&k)maxx=max(maxx,dfs(x+h,y+h,k-1,h,limit)+cost(y,x,h));
	}
	visit[y][x][k]=true;
	return dp[y][x][k]=maxx;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&cost1,&cost2);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mapp[i][j]);
	for(int i=1;i<=5;i++)
		for(int j=1;j*i<m;j++)
		{
			memset(dp,-1,sizeof dp);
			memset(visit,0,sizeof visit);
			int tmp=dfs(0,1,i,j,i)-cost1*(j-1)-cost2*(i-1);
			//printf("%d",tmp);
			if(tmp>ans)ans=tmp,ansj=i,ansh=j;
		}
	if(ans>0)printf("%d %d %d",ans,ansj,ansh);
	else printf("mission failed");	
	return 0;
}