#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=205;
int T,n;
int mapp[maxn][maxn],use[maxn],result[maxn];
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(mapp[x][i]&&!use[i])
		{
			use[i]=1;
			if(!result[i]||dfs(result[i])){
				result[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
bool xyl()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		memset(use,0,sizeof use);
		if(dfs(i))cnt++;
	}
	return cnt>=n;
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		memset(result,0,sizeof result);
		memset(mapp,0,sizeof mapp);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mapp[i][j]);
		printf("%s\n",xyl()?"Yes":"No");
	}
	return 0;
}
