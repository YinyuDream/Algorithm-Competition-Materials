#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=2000005;
struct node
{
	int to,next;
} edge[maxn<<1];
int k=0,head[maxn],n,m,c[maxn],son[maxn],ans=0;
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int x)
{
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=head[x];i;i=edge[i].next)
	{
		dfs(edge[i].to);
		q.push(c[edge[i].to]);
	}
	while(!q.empty())
	{
		if(c[x]+q.top()-1<=m) c[x]+=q.top()-1,q.pop(),ans++;
		else break;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&son[i]);c[i]+=son[i];
		for(int j=1,x;j<=son[i];j++)
		{
			scanf("%d",&x);
			x++;add(i,x);
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
