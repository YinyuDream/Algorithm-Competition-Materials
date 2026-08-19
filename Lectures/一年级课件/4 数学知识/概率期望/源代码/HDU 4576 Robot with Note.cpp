#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200+10;
int n,m,l,r;
double dp[2][maxn];//dp[i][j]表示当前到达j个格子机器人的概率，0-1数组优化 
int main()
{
	int w,cur,x,y;
	double ans;
	scanf("%d%d%d%d",&n,&m,&l,&r);
	while(n!=0 || m!=0 || l!=0 || r!=0){
		cur=ans=0;
		dp[cur][1]=1.0;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&w);
			w=w%n; cur=cur^1;
			for(int i=1;i<=n;i++) 
			{
				x=i+w;y=i-w;
				if(x>n) x=x-n;//循环格子，处理越界 
				if(y<1) y=y+n;//循环格子，处理越界
				//printf("%d %d\n",x,y);
				dp[cur][i]=dp[cur^1][x]*0.5+dp[cur^1][y]*0.5;
			}
		}
		for(int i=l;i<=r;i++) ans=ans+dp[cur][i];
		printf("%.4f\n",ans);
		scanf("%d%d%d%d",&n,&m,&l,&r);
	}	
	return 0;
}
 
