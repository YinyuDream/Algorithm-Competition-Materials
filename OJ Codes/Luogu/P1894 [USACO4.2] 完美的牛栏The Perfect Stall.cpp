#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int mapp[maxn][maxn];
int use[maxn],result[maxn];
bool dfs(int x)
{
	for(int i=1;i<=m;i++){
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
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,s;i<=n;i++){
		scanf("%d",&s);
		for(int j=1,u;j<=s;j++){
			scanf("%d",&u);
			mapp[i][u]=1;
		}
	}
	for(int i=1;i<=n;i++){
		memset(use,0,sizeof use);
		if(dfs(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
