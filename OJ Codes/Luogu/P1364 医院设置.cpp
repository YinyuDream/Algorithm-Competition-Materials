#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,a[maxn],f[maxn],ans=0x3f3f3f3f;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],size[maxn],deep[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
void dfs(int u,int fa)
{
	size[u]=a[u];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			deep[v]=deep[u]+1;
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
			f[v]=f[u]+size[1]-2*size[v];
			dp(v,u);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d%d",&a[i],&u,&v);
		if(u)
		add(i,u),add(u,i);
		if(v)
		add(i,v),add(v,i);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		f[1]+=deep[i]*a[i];
	dp(1,1);
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
