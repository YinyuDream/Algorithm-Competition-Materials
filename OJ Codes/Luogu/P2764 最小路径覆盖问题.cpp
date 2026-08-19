#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int mapp[maxn][maxn];
int result[maxn],use[maxn],fa[maxn];
bool dfs(int x)
{
	for(int i=1;i<=n;i++){
		if(mapp[x][i]&&!use[i]){
			use[i]=1;
			if(!result[i]||dfs(result[i])){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
void print(int x)
{
	if(result[x])print(result[x]);
	printf("%d ",x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),mapp[u][v]=1;
	for(int i=1;i<=n;i++){
		memset(use,0,sizeof use);
		if(dfs(i)){
			ans++;
		}
	}
	ans=n-ans;
	for(int i=1;i<=n;i++)
		fa[result[i]]=i;
	for(int i=1;i<=n;i++)
		if(!fa[i])
			print(i),puts("");
	printf("%d",ans);
	return 0;
}
