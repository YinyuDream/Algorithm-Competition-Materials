#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,d,type,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int dp[maxn][3];
void dfs(int u,int f)
{
	dp[u][0]=1;
	int mn=0x7f7f7f7f;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs(v,u);
			dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));//me
			dp[u][1]+=min(dp[v][0],dp[v][2]);//father
			dp[u][2]+=min(dp[v][0],dp[v][2]);//son
			mn=min(mn,max(0,dp[v][0]-dp[v][2]));
		}
	}
	dp[u][2]+=mn;
}
int main(){
	freopen("general.in","r",stdin);
	freopen("general.out","w",stdout);
	scanf("%d%d%d",&n,&d,&type);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(d==0)printf("%d\n",n);
	else if(d==1)dfs(1,1),printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
