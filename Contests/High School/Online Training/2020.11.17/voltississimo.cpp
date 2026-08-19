#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10,p=998244353;
int n,k;
ll ans;
struct node{
	int to,next,wt;
}edge[maxn*2];
int head[maxn],size[maxn];
ll jc[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
ll dp[maxn][maxn][4];//0:没有连边,1:out,2:in,3:连了两条边 
ll f[maxn][4];
void dfs(int u,int fa)
{
	dp[u][0][0]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa){
			dfs(v,u);
			memset(f,0,sizeof f);
			for(int j=0;j<=size[u];j++){
				for(int l=0;l<=size[v];l++){
					(f[j+l][0]+=dp[u][j][0]*(dp[v][l][0]+dp[v][l][1]+dp[v][l][2]+dp[v][l][3]))%=p;
					(f[j+l][1]+=dp[u][j][1]*(dp[v][l][0]+dp[v][l][1]+dp[v][l][2]+dp[v][l][3]))%=p;
					(f[j+l][2]+=dp[u][j][2]*(dp[v][l][0]+dp[v][l][1]+dp[v][l][2]+dp[v][l][3]))%=p;
					(f[j+l][3]+=dp[u][j][3]*(dp[v][l][0]+dp[v][l][1]+dp[v][l][2]+dp[v][l][3]))%=p;
					if(edge[i].wt==1)(f[j+l+1][1]+=dp[u][j][0]*(dp[v][l][0]+dp[v][l][1]))%=p;
					if(edge[i].wt==0)(f[j+l+1][2]+=dp[u][j][0]*(dp[v][l][0]+dp[v][l][2]))%=p;
					if(edge[i].wt==1)(f[j+l+1][3]+=dp[u][j][2]*(dp[v][l][0]+dp[v][l][1]))%=p;
					if(edge[i].wt==0)(f[j+l+1][3]+=dp[u][j][1]*(dp[v][l][0]+dp[v][l][2]))%=p;
				}
			}
			size[u]+=size[v];
			for(int j=0;j<=size[u];j++)
				for(int l=0;l<=3;l++)
					dp[u][j][l]=f[j][l];
		}
	}
	size[u]++;
}
int main(){
	freopen("voltississimo.in","r",stdin);
	freopen("voltississimo.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,0);
	}
	dfs(1,1);
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=(jc[i-1]*i)%p;
	for(int i=0;i<n;i++)
		(ans+=jc[n-i]*(dp[1][i][0]+dp[1][i][1]+dp[1][i][2]+dp[1][i][3])*((i&1)?-1:1))%=p;
	printf("%lld",(ans+p)%p);
	return 0;
}
