#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,k2,cnt,top,ans;
int a[maxn],new_a[maxn];
struct node{
	int from,to,next;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn],deg[maxn];
void add(int u,int v,int opt)
{
	if(opt==1)
	edge[++k]={u,v,head[u]},
	head[u]=k;
	else
	edge2[++k2]={u,v,head2[u]},
	head2[u]=k2;
}
int dfn[maxn],low[maxn],new_node[maxn],in_stack[maxn];
stack<int>s;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	s.push(u);
	in_stack[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in_stack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		while(s.top()!=u){
			new_node[s.top()]=cnt;
			in_stack[s.top()]=0;
			new_a[cnt]+=a[s.top()];
			s.pop();
		}
		new_node[s.top()]=cnt;
		in_stack[s.top()]=0;
		new_a[cnt]+=a[s.top()];
		s.pop();
	}
}
int dp[maxn];
queue<int>q;
void tp()
{
	for(int i=1;i<=cnt;i++)
		if(deg[i]==0)
			q.push(i),dp[i]=new_a[i],ans=max(ans,dp[i]);
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(int i=head2[t];i;i=edge2[i].next)
		{
			int v=edge2[i].to;
			dp[v]=max(dp[v],dp[t]+new_a[v]),
			ans=max(ans,dp[v]),
			deg[v]--;
			if(deg[v]==0)
			q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=m;i++)
	{
		int u=new_node[edge[i].from],v=new_node[edge[i].to];
		if(u!=v)
			add(u,v,2),deg[v]++;
	}
	tp();
	printf("%d",ans);
	return 0;
}
