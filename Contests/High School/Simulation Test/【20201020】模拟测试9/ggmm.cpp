#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,k2;
int val[maxn];
char s[maxn];
struct node{
	int to,next;
}edge[maxn*2],edge2[maxn*2];
int head[maxn],head2[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void add_edge(int u,int v)
{
	edge2[++k2].to=v;
	edge2[k2].next=head2[u];
	head2[u]=k2;
}
int dis[maxn],book[maxn];
queue<int>q;
void spfa()
{
	memset(dis,0x3f,sizeof dis);
	q.push(1);
	book[1]=1;
	dis[1]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+(val[v]==1)){
				dis[v]=dis[u]+(val[v]==1);
				if(!book[v]){
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}
int low[maxn],dfn[maxn],size[maxn],belong[maxn],deg[maxn],top,cnt;
stack<int>st;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	book[u]=1;
	st.push(u);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(book[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		while(st.top()!=u){
			size[cnt]+=(val[st.top()]==0);
			belong[st.top()]=cnt;
			book[st.top()]=0;
			st.pop();
		}
		size[cnt]+=(val[st.top()]==0);
		belong[st.top()]=cnt;
		book[st.top()]=0;
		st.pop();
	}
}
void dfs(int u)
{
	book[u]=1;
	for(int i=head2[u];i;i=edge2[i].next){
		int v=edge2[i].to;
		deg[v]++;
		if(!book[v])dfs(v);
	}
}
void topo()
{
	for(int i=1;i<=cnt;i++)
		if(!deg[i]&&book[i])
			q.push(i);
	while(q.size()){
		int u=q.front();
		q.pop();
		dis[u]+=size[u];
		for(int i=head2[u];i;i=edge2[i].next){
			int v=edge2[i].to;
			dis[v]=max(dis[v],dis[u]);
			deg[v]--;
			if(!deg[v]){
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("ggmm.in","r",stdin);
	freopen("ggmm.out","w",stdout);
	scanf("%d%d\n%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		val[i]=(s[i]=='M');
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		u++,v++;
		add(u,v);
	}
	spfa();
	printf("%d\n",dis[n]);
	memset(book,0,sizeof book);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(belong[i]!=belong[edge[j].to])
				add_edge(belong[i],belong[edge[j].to]);
	memset(dis,0,sizeof dis);
	dfs(belong[1]);
	topo();
	printf("%d\n",dis[belong[n]]);
	return 0;
}
