#pragma GCC optimize(3)
#include<cstdio>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=2e6+10;
int n,m,k,ans,cnt;
int h[maxn];
struct node{
	int to,next,wt;
}e[maxn];
struct edge{
	int u,v,w;
}q[maxn];
int head[maxn],book[maxn],fa[maxn],deg[maxn];
void add(int u,int v,int w)
{
	e[++k]={v,head[u],w};
	head[u]=k;
}
bool cmp(edge a,edge b)
{
	if(h[a.v]!=h[b.v])return h[a.v]>h[b.v];
	else return a.w<b.w;
}
void bfs()
{
	queue<int>q;
	book[1]=1;
	q.push(1);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(h[v]<=h[u]&&book[v]==0)
			book[v]=1,q.push(v);
		}
	}
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]),fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		q[i]={u,v,w};
		if(h[v]>h[u])swap(q[i].u,q[i].v);
		add(u,v,w);
		add(v,u,w);
	}
	bfs();
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=n;i++)
		if(book[i])
			cnt++;
	for(int i=1;i<=m;i++)
	{
		if(!book[q[i].u]||!book[q[i].v])continue;
		int fx=find(q[i].u),fy=find(q[i].v);
		if(fx!=fy)ans+=q[i].w,fa[fx]=fy;
	}
	printf("%lld %lld",cnt,ans);
	return 0;
}
