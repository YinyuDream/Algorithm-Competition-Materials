#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,m,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],w[maxn],p[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int dp[maxn][maxn];
void dfs(int u,int f)
{
	dp[u][0]=0;
	for(int i=p[u];i<=m;i++)
		dp[u][i]=w[u];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs(v,u);
			for(int j=m;j>=p[u];j--){
				for(int k=p[u];k<=j;k++){
					dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k]);
				}
			}
		}
	}
}
int main(){
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	memset(dp,-0x3f,sizeof dp);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&p[i]);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	printf("%d\n",dp[1][m]);
	return 0;
}
