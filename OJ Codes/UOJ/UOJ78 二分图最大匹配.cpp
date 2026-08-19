#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,k,ans;
int mp[maxn][maxn];
int use[maxn],result[maxn],t[maxn];
bool dfs(int x)
{
	for(int i=1;i<=m;i++){
		if(mp[x][i]&&!use[i]){
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
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=k;i++){
		scanf("%d%d",&u,&v);
		mp[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		memset(use,0,sizeof use);
		if(dfs(i))ans++;
	}
	for(int i=1;i<=m;i++)
		t[result[i]]=i;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",t[i]);
	return 0;
}