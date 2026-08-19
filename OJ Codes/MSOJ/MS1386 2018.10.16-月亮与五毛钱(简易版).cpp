#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
	return 0;
}