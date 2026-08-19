#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int T,n,m,ans;
int mapp[maxn][maxn],use[maxn],result[maxn];
bool dfs(int x,int t)
{
	for(int i=1;i<=n;i++){
		if(mapp[x][i]&&use[i]!=t){
			use[i]=t;
			if(!result[i]||dfs(result[i],t)){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(mapp,0,sizeof mapp);
		memset(use,0,sizeof use);
		memset(result,0,sizeof result);
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++)
			scanf("%d%d",&u,&v),
			mapp[u][v]=1;
		for(int i=1;i<=n;i++)
			if(dfs(i,i))
				ans++;
		printf("%d\n",n-ans);
	}
	return 0;
}
