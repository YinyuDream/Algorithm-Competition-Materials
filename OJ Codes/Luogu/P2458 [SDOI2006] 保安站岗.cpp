#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1510;
int n,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],w[maxn];
int dp[maxn][3],book[maxn];//0:选自己，1：选父亲,2:选儿子 
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int x)
{
	int minx=0x3f3f3f3f,cnt=0;
	dp[x][0]=w[x],dp[x][1]=dp[x][2]=0;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		dfs(v);
		dp[x][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		dp[x][1]+=min(dp[v][0],dp[v][2]);
		if(dp[v][0]<dp[v][2])cnt++;
		else minx=min(minx,dp[v][0]-dp[v][2]);
		dp[x][2]+=min(dp[v][0],dp[v][2]);
	}
	if(cnt==0)dp[x][2]+=minx; 
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int id,m;
		scanf("%d",&id);
		scanf("%d%d",&w[id],&m);
		for(int j=1,v;j<=m;j++)
		scanf("%d",&v),add(id,v),book[v]=1;
	}
	int root=-1;
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			root=i;
			break;
		}
	} 
	dfs(root);
	printf("%d",min(dp[root][0],dp[root][2]));
	return 0;
} 
