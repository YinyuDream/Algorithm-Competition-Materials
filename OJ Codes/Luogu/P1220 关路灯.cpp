#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=51;
int n,c;
int p[maxn],w[maxn],sum[maxn];
int f[maxn][maxn][2];
int dfs(int l,int r,int a)
{
	if(f[l][r][a]!=-1)return f[l][r][a];
	int ans=0x3f3f3f3f;
	if(a==0){
		if(l<r)ans=min(dfs(l+1,r,0)+(p[l+1]-p[l])*(sum[n]-(sum[r]-sum[l])),dfs(l+1,r,1)+(p[r]-p[l])*(sum[n]-(sum[r]-sum[l])));
	}else{
		if(l<r)ans=min(dfs(l,r-1,1)+(p[r]-p[r-1])*(sum[n]-(sum[r-1]-sum[l-1])),dfs(l,r-1,0)+(p[r]-p[l])*(sum[n]-(sum[r-1]-sum[l-1])));
	}
	return f[l][r][a]=ans;
} 
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i],&w[i]),sum[i]=sum[i-1]+w[i];
	memset(f,-1,sizeof f);
	f[c][c][0]=f[c][c][1]=0;
	printf("%d",min(dfs(1,n,0),dfs(1,n,1)));
	return 0;
} 
