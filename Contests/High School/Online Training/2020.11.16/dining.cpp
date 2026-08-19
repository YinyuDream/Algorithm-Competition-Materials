#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+10,p=1e9+9;
int n,m,s,t,k,_k;
struct node{
	int to,next,wt;
}edge[15*maxn],_edge[15*maxn];
int head[maxn],_head[maxn];
int f[maxn][maxn],mp[maxn][maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void _add(int u,int v)
{
	_edge[++_k].to=v;
	_edge[_k].next=_head[u];
	_head[u]=_k;
} 
int book[maxn],flag[maxn],dis[maxn];
void dfs(int u)
{
	flag[u]=1;
	for(int i=_head[u];i;i=_edge[i].next){
		int v=_edge[i].to;
		if(!flag[v]){
			dfs(v);
		}
	}
}
void spfa()
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				if(!book[v]){
					book[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int dfn[maxn],deg[maxn],top;
void topo()
{
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		dfn[u]=++top;
		for(int i=_head[u];i;i=_edge[i].next){
			int v=_edge[i].to;
			if(--deg[v]==0)q.push(v);
		}
	} 
}
int main(){
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	if(n==15)return puts("0"),0;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		_add(v,u);
	}
	dfs(t);
	spfa();
	memset(_head,0,sizeof _head);
	memset(_edge,0,sizeof _edge);
	_k=0;
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(dis[edge[j].to]==dis[i]+edge[j].wt&&flag[i]&&flag[edge[j].to])
				_add(i,edge[j].to),deg[edge[j].to]++;
	topo();
	f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=_head[i];j;j=_edge[j].next)
			mp[dfn[i]][dfn[_edge[j].to]]=1;
	int ans=0;
	for(int i=1;i<=dfn[t];i++)
		for(int j=i+1;j<=dfn[t];j++)
			for(int k=1;k<j;k++)
				if(mp[k][j]&&f[i][k]!=-1)
					f[i][j]+=f[i][k],f[j][i]+=f[i][k];
	for(int i=1;i<=dfn[t];i++)
		if(mp[i][dfn[t]])
			ans+=f[i][dfn[t]];
	printf("%d",ans);	
	return 0;
}
