#include<cstdio>
#include<stack>
using namespace std;
const int maxn=1e3+10;
int n,m,k,k2,top,cnt;
int w[maxn],v[maxn],d[maxn],f[maxn][maxn];
struct node{
	int from,to,next;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn];
stack<int>st;
int low[maxn],dfn[maxn],news[maxn],in_stack[maxn],deg[maxn];
int _w[maxn],_v[maxn];
void add(int u,int v,int opt)
{
	if(opt==1)
	edge[++k].from=u,
	edge[k].to=v,
	edge[k].next=head[u],
	head[u]=k;
	else
	edge2[++k2].from=u,
	edge2[k2].to=v,
	edge2[k2].next=head2[u],
	head2[u]=k2;
}
void tarjan(int u)
{
	low[u]=dfn[u]=++top;
	st.push(u);
	in_stack[u]=true;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]) 
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in_stack[v]) 
		{
			low[u]=min(low[u],dfn[v]); 
		}
	} 
	if(low[u]==dfn[u])
	{
		cnt++;
		while(st.top()!=u){
			_w[cnt]+=w[st.top()];
			_v[cnt]+=v[st.top()];
			in_stack[st.top()]=false;
			news[st.top()]=cnt;
			st.pop();
		}
		_w[cnt]+=w[st.top()];
		_v[cnt]+=v[st.top()];
		in_stack[st.top()]=false;
		news[st.top()]=cnt;
		st.pop();
	}
}
void dfs(int u)
{
	for(int i=_w[u];i<=m;i++)
		f[u][i]=_v[u];
	for(int i=head2[u];i;i=edge2[i].next){
		int v=edge2[i].to;
		dfs(v);
		for(int j=m;j>=_w[u];j--)
			for(int k=0;j-k>=_w[u];k++)
				f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(d[i])add(d[i],i,1);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=k;i++)
		if(news[edge[i].from]!=news[edge[i].to])
			add(news[edge[i].from],news[edge[i].to],2),
			deg[news[edge[i].to]]++;
	for(int i=1;i<=cnt;i++)
		if(deg[i]==0)
			add(0,i,2);
	dfs(0);
	printf("%d",f[0][m]);
	return 0;
}