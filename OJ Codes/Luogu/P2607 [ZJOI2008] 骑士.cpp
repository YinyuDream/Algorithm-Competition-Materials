#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,tot;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],w[maxn],c[maxn],is_circle[maxn],fa[maxn],book[maxn],belong[maxn],size[maxn],sum[maxn],cnt,ans;
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
bool find(int u)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]==1)
		{
			int t=u;
			while(t!=v)
			{
				is_circle[t]=1;
				c[++cnt]=t;
				belong[t]=tot;
				size[tot]++;
				t=fa[t];
			}
			is_circle[t]=1;
			c[++cnt]=t;
			belong[t]=tot;
			size[tot]++;
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
int f[maxn][2],g[maxn][2][2];
void dfs(int u,int _f)
{
	f[u][1]=w[u];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=_f&&is_circle[v]==0)
		{
			dfs(v,u);
			f[u][0]+=max(f[v][0],f[v][1]);
			f[u][1]+=f[v][0];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d%d",&w[i],&t);
		add(t,i);
	}
	for(int i=1;i<=n;i++)
		if(!book[i])
			tot++,find(i);
	for(int i=1;i<=cnt;i++)
		dfs(c[i],c[i]);
	for(int i=1;i<=tot;i++)
		sum[i]=sum[i-1]+size[i];
	for(int i=1;i<=tot;i++)
	{
		g[1][0][0]=f[c[sum[i-1]+1]][0];
		g[1][1][1]=f[c[sum[i-1]+1]][1];
		for(int j=2;j<=size[i];j++)
		{
			g[j][0][0]=max(g[j-1][0][0],g[j-1][1][0])+f[c[sum[i-1]+j]][0];
			g[j][0][1]=max(g[j-1][0][1],g[j-1][1][1])+f[c[sum[i-1]+j]][0];
			g[j][1][0]=g[j-1][0][0]+f[c[sum[i-1]+j]][1];
			g[j][1][1]=g[j-1][0][1]+f[c[sum[i-1]+j]][1];
		}
		ans+=max(g[size[i]][0][0],max(g[size[i]][1][0],g[size[i]][0][1]));
	}
	printf("%d",ans);
	return 0;
}