#include<cstdio>
#include<algorithm>
#include<cmath>
const int maxn=12;
using namespace std;
int a,b,n;
int sum[maxn][maxn];
double dp[maxn][maxn][maxn][maxn][maxn];
double avg;
double dfs(int x1,int y1,int x2,int y2,int cnt)
{
	if(dp[x1][y1][x2][y2][cnt])return dp[x1][y1][x2][y2][cnt];
	if(cnt==0)
	{
		double sumq=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
		return (sumq-avg)*(sumq-avg);
	}
	dp[x1][y1][x2][y2][cnt]=0x7f7f7f7f;
	for(int i=x1;i<x2;i++)
		for(int j=0;j<cnt;j++)
			dp[x1][y1][x2][y2][cnt]=min(dp[x1][y1][x2][y2][cnt],dfs(x1,y1,i,y2,j)+dfs(i+1,y1,x2,y2,cnt-j-1));
	for(int i=y1;i<y2;i++)
		for(int j=0;j<cnt;j++)
			dp[x1][y1][x2][y2][cnt]=min(dp[x1][y1][x2][y2][cnt],dfs(x1,y1,x2,i,j)+dfs(x1,i+1,x2,y2,cnt-j-1));
	return dp[x1][y1][x2][y2][cnt];		
}
int main(){
	int m=0;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			scanf("%d",&m),
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+m;
	avg=(double)sum[a][b]/n;
	printf("%.2f",sqrt(dfs(1,1,a,b,n-1)/n));
	return 0;	
}