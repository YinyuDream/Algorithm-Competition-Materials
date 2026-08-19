#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000+10;
const int inf=0x7f7f7f7f;
struct nod
{
	int next,to,w;
}e[maxn*10];
int head[maxn],x[maxn],y[maxn],dis[maxn];
int n,m,k=1,ans,s,t,l,w;
bool vis[maxn];
void add(int u,int v,int w)
{
	e[++k].next=head[u];e[k].to=v;e[k].w=w;head[u]=k;
	e[++k].next=head[v];e[k].to=u;e[k].w=0;head[v]=k;
}
bool bfs(int s,int t)
{
	queue<int>q;q.push(s);
	memset(dis,-1,sizeof(dis));dis[s]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].next)
		{
			if(dis[e[i].to]==-1 && e[i].w)
			{
				dis[e[i].to]=dis[now]+1;
				if(e[i].to==t) return true;
				q.push(e[i].to);
			}
		}
	}return false;
}
int dfs(int x,int f)
{
	if(x==t) return f;
	int use=f;
	for(int i=head[x];i;i=e[i].next)
	{
		if(dis[e[i].to]==dis[x]+1 && e[i].w && use)
		{
			int flow=dfs(e[i].to,min(use,e[i].w));
			if(!flow) dis[e[i].to]=-1;
			use-=flow;e[i].w-=flow;e[i^1].w+=flow;
		}
	}return f-use;
}
void Din()
{
	ans=0;
	while(bfs(s,t))
		ans+=dfs(s,inf);
}
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%d%d%d",&l,&w,&n);s=0;t=2*n+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]<=100) add(s,i,1);
		if(w-y[i]<=100) add(i+n,t,1);
	}
	for(int i=1;i<=n;i++)add(i,i+n,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double L=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(L<=200.0)
			{
				add(i+n,j,1);add(j+n,i,1);
			}
		}
	}
	Din();printf("%d\n",ans);
}
