#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,cnt_edge,dis,dis2=-0x7f7f7f7f,l,r,p;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],f[maxn],g[maxn],nx[maxn],book[maxn];
void add(int u,int v)
{
	edge[++cnt_edge]={v,head[u],1};
	head[u]=cnt_edge;
}
void dfs(int u,int fa,int d,int o)
{
	if(dis<=d)dis=d,(o==1?l=u:r=u);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		dfs(v,u,d+1,o);
	}
}
bool dfs2(int u,int fa,int ed)
{
	if(u==ed)return true;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			nx[u]=v;
			if(dfs2(v,u,ed))return true;
		}
	}
}
void dp(int u,int fa)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			dp(v,u);
			dis2=max(dis2,g[u]+g[v]+edge[i].wt);
			g[u]=max(g[u],g[v]+edge[i].wt);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1,0,1);
	dfs(l,l,0,2);
	if(k==1)return printf("%d",2*(n-1)-dis+1),0;
	dfs2(l,l,r);
	p=l;
	while(p!=r)book[p]=1,p=nx[p];
	book[p]=1;
	for(int i=1;i<=n;i++)
		if(book[i])
			for(int j=head[i];j;j=edge[j].next)
				if(book[edge[j].to])
					edge[j].wt=-1;
	dp(1,1);
	printf("%d",2*n-dis-((dis2<0)?0:dis2));
	return 0;
}
