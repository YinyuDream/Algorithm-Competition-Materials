#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,k,l,root;
int a[maxn],Nroot[maxn];
int dp[maxn][2];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v,int x)
{
	edge[x].to=v;
	edge[x].next=head[u];
	head[u]=x;
}
void dfs(int x)
{
	dp[x][0]=0,dp[x][1]=a[x];
	for(int i=head[x];i>0;i=edge[i].next)
	{
		int w=edge[i].to;
		dfs(w);
		dp[x][0]+=max(dp[w][0],dp[w][1]),dp[x][1]+=dp[w][0];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<n;i++)
		scanf("%d%d",&l,&k),add(k,l,i),Nroot[l]=1;
	scanf("%d%d",&k,&l);
	for(int i=1;i<=n;i++)
		if(Nroot[i]==0)
		{
			root=i;
			break;
		}
	dfs(root);
	printf("%d",max(dp[root][0],dp[root][1]));
	return 0;
}