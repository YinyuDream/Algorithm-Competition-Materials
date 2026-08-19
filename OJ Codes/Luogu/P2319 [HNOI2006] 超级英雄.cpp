#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m,cnt;
int mapp[maxn][maxn],result[maxn],use[maxn],ans[maxn];
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(mapp[x][i]&&!use[i])
		{
			use[i]=1;
			if(!result[i]||dfs(result[i]))
			{
				result[i]=x;
				ans[x]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u++,v++;
		mapp[i][u]=mapp[i][v]=1;
	}
	for(int i=1;i<=m;i++)
	{
		memset(use,0,sizeof use);
		if(dfs(i))cnt++;
		else break;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	printf("%d\n",ans[i]-1);
	return 0;
}
