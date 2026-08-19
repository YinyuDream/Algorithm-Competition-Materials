#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
bool map[maxn][maxn],book[maxn];
int n,m,ans1,ans2;
queue<int>q;
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(book[i]==1)continue;
		if(map[x][i]==1)
		{
			book[i]=1;
			dfs(i);
		}
	}
}
void bfs(int x)
{
	q.push(x);book[x]=1;
	while(q.size())
	{
		int u=q.front();q.pop();
		for(int i=1;i<=n;i++)
		{
			if(book[i])continue;
			if(map[u][i]==1)
			{
				book[i]=1;
				q.push(i);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int k,j;
		scanf("%d%d",&k,&j);
		map[k][j]=1;
		map[j][k]=1;
	}
	for(int j=1;j<=n;j++)
	{
		if(book[j]==0)
		{
			book[j]=1;ans1++;dfs(j);	
		}
	}
	memset(book,0,sizeof(book));
	for(int j=1;j<=n;j++)
	{
		if(book[j]==0)
		{
			book[j]=1;ans2++;bfs(j);	
		}
	}
	printf("%d",(ans1+ans2)/2);
	return 0;
}
