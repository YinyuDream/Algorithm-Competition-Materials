#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],t[maxn],deg[maxn],dp[maxn];
queue<int>q;
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,v,len;	
		scanf("%d%d",&u,&len);
		t[u]=len;
		while(1)
		{
			scanf("%d",&v);
			if(v==0)break;
			deg[u]++;
			add(v,u);
		}
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			q.push(i);
	while(q.size())
	{
		int u=q.front();
		dp[u]+=t[u];
		ans=max(ans,dp[u]);
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			dp[v]=max(dp[v],dp[u]);
			deg[v]--;
			if(deg[v]==0)
			q.push(v);
		}
	}
	printf("%d",ans);
	return 0;
}
