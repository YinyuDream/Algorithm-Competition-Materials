#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,k2,k3,cnt,top,ans,s,p;
int a[maxn],new_a[maxn];
struct node{
	int from,to,next;
}edge[maxn],edge2[maxn],edge3[maxn];
int head[maxn],head2[maxn],head3[maxn],deg[maxn];
void add(int u,int v,int opt)
{
	if(opt==1)
	edge[++k]={u,v,head[u]},
	head[u]=k;
	else if(opt==2)
	edge2[++k2]={u,v,head2[u]},
	head2[u]=k2;
	else
	edge3[++k3]={u,v,head3[u]},
	head3[u]=k3;
}
int dfn[maxn],low[maxn],new_node[maxn],in_stack[maxn],book[maxn],num[maxn];
stack<int>st;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	st.push(u);
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
		while(st.top()!=u){
			new_node[st.top()]=cnt;
			in_stack[st.top()]=0;
			new_a[cnt]+=a[st.top()];
			if(book[st.top()])num[cnt]++;
			st.pop();
		}
		new_node[st.top()]=cnt;
		in_stack[st.top()]=0;
		new_a[cnt]+=a[st.top()];
		if(book[st.top()])num[cnt]++;
		st.pop();
	}
}
void dfs(int u)
{
	book[u]=1;
	for(int i=head2[u];i;i=edge2[i].next)
	{
		int v=edge2[i].to;
		if(book[v]==0)
		dfs(v);
	}
}
int dp[maxn];
queue<int>q;
void tp()
{
	for(int i=1;i<=cnt;i++)
		if(deg[i]==0)
			q.push(i),(dp[i]=book[i]==1?new_a[i]:0);
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(int i=head2[t];i;i=edge2[i].next)
		{
			int v=edge2[i].to;
			dp[v]=(book[v]==1?max(dp[v],dp[t]+new_a[v]):0);
			deg[v]--;
			if(deg[v]==0)
			q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;i++)
	{
		int x;
		scanf("%d",&x);
		book[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=m;i++)
	{
		int u=new_node[edge[i].from],v=new_node[edge[i].to];
		if(u!=v){
			add(u,v,2);deg[v]++;
		}
	}
	memset(book,0,sizeof book);
	dfs(new_node[s]);
	tp();
	for(int i=1;i<=cnt;i++)
		if(num[i]>0)
			ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
