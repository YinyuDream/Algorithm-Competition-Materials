#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
int c[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],size[maxn],deep[maxn];
long long ans=0x7f7f7f7f7f7f7f7fll,f[maxn];
void add(int u,int v,int w)
{
	edge[++k]={v,head[u],w};
	head[u]=k;
}
void dfs(int u,int fa)
{
	size[u]=c[u];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			deep[v]=deep[u]+edge[i].wt;
			dfs(v,u);
			size[u]+=size[v];
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
			f[v]=f[u]+(1ll*size[1]-2*size[v])*edge[i].wt;
			dp(v,u);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		f[1]+=1ll*deep[i]*c[i];
	dp(1,1);
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
