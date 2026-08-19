#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,k,sum;
struct node{
	int to,next,wt;
}edge[maxn*2];
int head[maxn],dis[maxn],ans[maxn],size[maxn];
int f[maxn][18]; 
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int fa)
{
	f[u][0]=size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa){
			dis[v]=dis[u]+edge[i].wt;
			dfs(v,u);
			for(int j=0;j<=15;j++)
				f[u][(j+edge[i].wt)&15]+=f[v][j];
			size[u]+=size[v];
		}
	}
}
void dp(int u,int fa,int sum)
{
	ans[u]=sum;
	for(int i=1;i<=15;i++)
		ans[u]-=f[u][i]*i;
	f[u][0]--;
	for(int i=0;i<=15;i++)
		ans[u]+=f[u][i]*(i^m);
	f[u][0]++;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa){
			for(int j=0;j<=15;j++)
				f[u][(j+edge[i].wt)&15]-=f[v][j];
			for(int j=0;j<=15;j++)
				f[v][(j+edge[i].wt)&15]+=f[u][j];
			dp(v,u,sum+(n-2*size[v])*edge[i].wt);
			for(int j=0;j<=15;j++)
				f[v][(j+edge[i].wt)&15]-=f[u][j];
			for(int j=0;j<=15;j++)
				f[u][(j+edge[i].wt)&15]+=f[v][j];
		}
	}
}
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		sum+=dis[i];
	dp(1,1,sum);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
