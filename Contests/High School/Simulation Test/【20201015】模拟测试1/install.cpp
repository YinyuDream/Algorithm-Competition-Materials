#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,k;
int v[maxn],w[maxn],d[maxn],top;
int dfn[maxn],low[maxn],in[maxn],_v[maxn],_w[maxn],belong[maxn],deg[maxn],cnt;
stack<int>st;
struct node{
	int to,next;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void add_edge(int u,int v)
{
	edge2[++k].to=v;
	edge2[k].next=head2[u];
	head2[u]=k;
}
int dp[maxn][maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	in[u]=true;
	st.push(u);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		while(st.top()!=u){
			_v[cnt]+=v[st.top()];
			_w[cnt]+=w[st.top()];
			belong[st.top()]=cnt;
			in[st.top()]=false;
			st.pop();
		}
		_v[cnt]+=v[st.top()];
		_w[cnt]+=w[st.top()];
		belong[st.top()]=cnt;
		in[st.top()]=false;
		st.pop();
	}
}
void dfs(int u,int f)
{
	for(int i=_v[u];i<=m;i++)
		dp[u][i]=_w[u];
	for(int i=head2[u];i;i=edge2[i].next){
		int to=edge2[i].to;
		if(to!=f){
			dfs(to,u);
			for(int j=m;j>=_v[u];j--){
				for(int k=0;j-k>=_v[u];k++){
					dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[to][k]);
				}
			}
		}
	}
}
int main(){
	freopen("install.in","r",stdin);
	freopen("install.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i])add(d[i],i);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	k=0;
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(belong[i]!=belong[edge[j].to])
				add_edge(belong[i],belong[edge[j].to]),deg[belong[edge[j].to]]++;
	for(int i=1;i<=cnt;i++)
		if(!deg[i])
			add_edge(0,i);
	dfs(0,0);
	printf("%d\n",dp[0][m]);
	return 0;
}
