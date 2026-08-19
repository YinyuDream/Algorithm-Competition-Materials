#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000005;
int n,p[maxn],head[maxn],f[maxn][2],s,t,k=1;
double radio;
bool visit[maxn],cant[maxn];
struct node
{
	int to,next;
} edge[maxn<<1];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs_pre(int x,int fa)
{
	visit[x]=true;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		if(visit[edge[i].to])
		{
			s=x;t=edge[i].to;
			cant[i]=cant[i^1]=true;
			return;
		}
		dfs_pre(edge[i].to,x);
	}
}
void dfs(int x,int fa)
{
	//f[][0]:²»¿ªµê,f[][1]¿ªµê 
	f[x][0]=f[x][1]=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa||cant[i]) continue;
		dfs(edge[i].to,x);
		f[x][0]+=max(f[edge[i].to][0],f[edge[i].to][1]);
		f[x][1]+=f[edge[i].to][0];
	}
	f[x][1]+=p[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1,a,b;i<=n;i++)
	{
		scanf("%d%d",&a,&b);a++;b++;
		add(a,b);add(b,a);
	}
	scanf("%lf",&radio);
	dfs_pre(1,1);
	dfs(s,s);
	int t1=f[s][0];
	dfs(t,t);
	int t2=f[t][0];
	int ans=max(t1,t2);
	printf("%.1f\n",(double)ans*radio);
	return 0;
}
