#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e4+10;
int n,m,ans,k;
struct node{
	int to,next,weight;
}edge[maxn];
int head[maxn],w[maxn];
int dp[maxn][maxn];//以i为结点的子树给j个人提供信号的最大收益 
void add(int u,int v,int w)
{
	edge[++k].to=v,edge[k].next=head[u],edge[k].weight=w,head[u]=k;
}
int dfs(int x)
{
	if(x>n-m){
		dp[x][1]=w[x];
		return 1;
	}
	int sum=0,cnt=0;
	for(int i=head[x];i;i=edge[i].next)//sonsize组物品 
	{
		int nx=edge[i].to;
		cnt=dfs(nx),sum+=cnt;
		for(int v=sum;v>0;v--)//背包容量
		{
			for(int j=1;j<=cnt;j++)//每个子树的第j(1<j<m)个物品价值为dp[v][j],大小为j 
			{
				if(v>=j)
				{
					dp[x][v]=max(dp[x][v],dp[x][v-j]+dp[nx][j]-edge[i].weight);
				}
			}
		}
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m-1;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]=-0x3f3f3f3f;
	for(int i=1,t;i<=n-m;i++){
		scanf("%d",&t);
		for(int j=1,a,c;j<=t;j++){
			scanf("%d%d",&a,&c);
			add(i,a,c);
		}
	}
	for(int i=n-m+1;i<=n;i++)
		scanf("%d",&w[i]); 
	dfs(1);
	for(int i=m;i>=1;i--){
		if(dp[1][i]>=0){
			printf("%d",i);
			break;
		}
	}
	return 0;
} 
