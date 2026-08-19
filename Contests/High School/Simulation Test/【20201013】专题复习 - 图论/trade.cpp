#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,k,p,top,cnt,ans;
int w[maxn];
struct node{
	int to,next;
}edge[maxn],edge2[maxn],edge3[maxn];
int head[maxn],head2[maxn],head3[maxn];
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
	swap(u,v);
	edge3[++p].to=v;
	edge3[p].next=head3[u];
	head3[u]=p;
}
int dfn[maxn],low[maxn],in[maxn],belong[maxn],maxx[maxn],minx[maxn],deg[maxn],deg2[maxn],f[maxn],g[maxn];
stack<int>st;
void tarjan(int u)
{
	low[u]=dfn[u]=++top;
	st.push(u);
	in[u]=1;
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
			belong[st.top()]=cnt;
			in[st.top()]=0;
			minx[cnt]=min(minx[cnt],w[st.top()]);
			maxx[cnt]=max(maxx[cnt],w[st.top()]);
			st.pop();
		}
		belong[st.top()]=cnt;
		in[st.top()]=0;
		minx[cnt]=min(minx[cnt],w[st.top()]);
		maxx[cnt]=max(maxx[cnt],w[st.top()]);
		st.pop();
	}
}
queue<int>q;
void tp()
{
	for(int i=1;i<=cnt;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==belong[1]||f[u])f[u]=min(f[u],minx[u]);
		for(int i=head2[u];i;i=edge2[i].next){
			int v=edge2[i].to;
			deg[v]--;
			f[v]=min(f[u],f[v]);
			if(!deg[v]){
				q.push(v);
			}
		}
	}
	for(int i=1;i<=cnt;i++)
		if(!deg2[i])
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==belong[n]||g[u])g[u]=max(g[u],maxx[u]);
		for(int i=head3[u];i;i=edge3[i].next){
			int v=edge3[i].to;
			deg2[v]--;
			g[v]=max(g[v],g[u]);
			if(!deg2[v]){
				q.push(v);
			}
		}
	}
}
int main(){
	memset(minx,0x3f,sizeof minx);
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v);
		if(w==2)add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	k=0;
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(belong[i]!=belong[edge[j].to])
				add_edge(belong[i],belong[edge[j].to]),
				deg[belong[edge[j].to]]++,deg2[belong[i]]++;
	tp();
	for(int i=1;i<=cnt;i++)
		ans=max(ans,g[i]-f[i]);
	printf("%d",ans);
	return 0;
}
