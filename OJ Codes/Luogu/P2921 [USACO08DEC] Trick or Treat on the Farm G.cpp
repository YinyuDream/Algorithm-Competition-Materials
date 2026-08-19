#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,ans=0x7f7f7f7f,k,k2,circle;
struct node{
	int from,to,next;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn];
void add(int u,int v,int opt)
{
	if(opt==1)
	edge[++k]={u,v,head[u]},
	head[u]=k;
	else
	edge2[++k2]={u,v,head2[u]},
	head2[u]=k2;
}
int top,tot,dfn[maxn],low[maxn],news[maxn],cnt[maxn],in[maxn],deg[maxn],depth[maxn],root[maxn];
stack<int>s;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	s.push(u);
	in[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		tot++;
		while(s.top()!=u)
		{
			news[s.top()]=tot;
			cnt[tot]++;
			in[s.top()]=0;
			s.pop();
		}
		news[s.top()]=tot;
		cnt[tot]++;
		in[s.top()]=0;
		s.pop();
	}
}
void dfs(int u,int dis,int rot)
{
	dfn[u]=1;depth[u]=dis;root[u]=rot;
	for(int i=head2[u];i;i=edge2[i].next)
	{
		int v=edge2[i].to;
		if(!dfn[v])
		dfs(v,dis+1,rot);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		if(v==i){
			circle++;
			continue;
		}
		add(i,v,1);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n-circle;i++)
	{
		int fx=news[edge[i].from],fy=news[edge[i].to];
		if(fx!=fy)
		add(fy,fx,2),deg[fx]++;
	}
	memset(dfn,0,sizeof dfn);
	for(int i=1;i<=tot;i++)
		if(deg[i]==0)
			dfs(i,0,i);
	for(int i=1;i<=n;i++)
		printf("%d\n",depth[news[i]]+cnt[root[news[i]]]);
	return 0;
}
