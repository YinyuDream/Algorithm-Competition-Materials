#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=4e4+10;
int n;
int a[maxn],b[maxn],c[maxn],l[maxn],r[maxn];
long long dp[maxn][41][41];
long long dfs(int u,int x,int y)
{
	if(u>n)return 1ll*c[u]*(a[u]+x)*(b[u]+y);
	if(dp[u][x][y])return dp[u][x][y];
	return dp[u][x][y]=min(dfs(l[u],x,y)+dfs(r[u],x,y+1),dfs(l[u],x+1,y)+dfs(r[u],x,y));
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		l[i]=u>0?u:n-u;
		r[i]=v>0?v:n-v;
	}
	for(int i=n+1;i<=n*2;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	printf("%lld",dfs(1,0,0));
	return 0;
}