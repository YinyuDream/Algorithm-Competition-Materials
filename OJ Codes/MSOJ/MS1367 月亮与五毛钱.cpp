#pragma GCC optimize(3)
#include<stack>
#include<queue>
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
deque<pair<int,int> >dq;
queue<int>q;
void bfs()
{
	dq.push_back(make_pair(1,val[1]));
	while(dq.size())
	{
		pair<int,int> u=dq.front();
		dq.pop_front();
		if(book[u.first])continue;
		dis[u.first]=u.second;
		book[u.first]=1;
		for(int i=head[u.first];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v])continue;
			if(val[v])dq.push_back(make_pair(v,u.second+1));
			else dq.push_front(make_pair(v,u.second));
		}
	}
}
int dfn[maxn],low[maxn],size[maxn],belong[maxn],deg[maxn],cnt,top;
stack<int>st;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	st.push(u);
	book[u]=1;
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
			size[cnt]+=!val[st.top()];
			belong[st.top()]=cnt;
			book[st.top()]=0;
			st.pop();
		}
		size[cnt]+=!val[st.top()];
		belong[st.top()]=cnt;
		book[st.top()]=0;
		st.pop();
	}
}
void topo()
{
	for(int i=1;i<=cnt;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		dis[u]+=size[u];
		q.pop();
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
	scanf("%d%d\n%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		val[i]=(s[i]=='M');
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		u++,v++;
		add(u,v);
	}
	bfs();
	printf("%d\n",dis[n]);
	tarjan(1);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(dfn[i]&&dfn[edge[j].to]&&belong[i]!=belong[edge[j].to])
				add_edge(belong[i],belong[edge[j].to]),deg[belong[edge[j].to]]++;
	memset(dis,0,sizeof dis);
	topo();
	printf("%d",dis[belong[n]]);
	return 0;
}
