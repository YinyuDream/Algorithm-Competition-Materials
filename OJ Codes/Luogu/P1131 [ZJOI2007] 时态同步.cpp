#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,s,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
long long dp[maxn],sum[maxn];
void add(int u,int v,int w)
{
	edge[++k]={v,head[u],w};
	head[u]=k;
}
void dfs(int u,int f)
{
	//printf("%d",u);
	long long val=0,cnt=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			dfs(v,u);
			val=max(val,sum[v]+edge[i].wt);
		}
	}
	sum[u]=val;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			cnt+=val-(sum[v]+edge[i].wt);
			dp[u]+=dp[v];
		}
	}
	dp[u]+=cnt;
}
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(s,s);
	printf("%lld",dp[s]);
	return 0;
}
