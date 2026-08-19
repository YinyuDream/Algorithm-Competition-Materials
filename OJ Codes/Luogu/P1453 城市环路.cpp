#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,p[maxn],cnt_edge;
double k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	head[u]=cnt_edge;
}
int fa[maxn],is_circle[maxn],c[maxn],book[maxn],cnt;
int f[maxn][2];
bool find(int u)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]==1)
		{
			if(v==fa[u])continue;
			int t=u;
			while(t!=v)
			{
				is_circle[t]=1;
				c[++cnt]=t;
				t=fa[t];
			}
			is_circle[t]=1;
			c[++cnt]=t;
			return true;
		}
		else
		{
			fa[v]=u;
			if(find(v))return true;
		}
	}
	return false;
}
void dfs(int u,int _f)
{
	f[u][1]=p[u];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=_f&&is_circle[v]==0)
		{
			dfs(v,u);
			f[u][1]+=f[v][0];
			f[u][0]+=max(f[v][0],f[v][1]);
		}
	}
}
int g[maxn][2][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u++,v++;
		add(u,v);
		add(v,u);
	}
	scanf("%lf",&k);
	find(1);
	for(int i=1;i<=cnt;i++)
		dfs(c[i],c[i]);
	g[1][0][0]=f[c[1]][0];
	g[1][1][1]=f[c[1]][1];
	for(int i=2;i<=cnt;i++)
	{
		g[i][0][0]=max(g[i-1][0][0],g[i-1][1][0])+f[c[i]][0];
		g[i][0][1]=max(g[i-1][0][1],g[i-1][1][1])+f[c[i]][0];
		g[i][1][0]=g[i-1][0][0]+f[c[i]][1];
		g[i][1][1]=g[i-1][0][1]+f[c[i]][1];
	}
	printf("%.1lf",k*max(max(g[cnt][1][0],g[cnt][0][1]),g[cnt][0][0]));
	return 0;
}
