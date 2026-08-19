#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1.5e2+10;
int n,p,root,NotRoot[maxn],u,v;
int head[maxn],cnt[maxn];
int dp[maxn][maxn];
struct node{
	int to,next;
}edge[maxn];
void add(int u,int v,int w)
{
	edge[w].to=v;
	edge[w].next=head[u];
	head[u]=w;
}
int dfs(int x)
{
	int sum=1;
	for(int i=head[x];i>0;i=edge[i].next)
	{
		sum+=dfs(edge[i].to);
		for(int j=sum;j>=1;j--)
			for(int k=1;k<j;k++)
				dp[x][j]=min(dp[x][j],dp[x][j-k]+dp[edge[i].to][k]-1);
	}
	return sum;
}
void get()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),add(u,v,i),NotRoot[v]=1,cnt[u]++;
	memset(dp,0x7f,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(!NotRoot[i])root=i;
		dp[i][1]=cnt[i];
	}	
}
int main(){
	get();
	dfs(root);
	int ans=dp[root][p];
	for(int i=1;i<=n;i++)
		ans=ans>dp[i][p]?dp[i][p]+1:ans;
	printf("%d",ans);
	return 0;
}