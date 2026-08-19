#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10,mod=1e5+3;
int n,m,k;
struct node{
	int to,next;
}edge[maxn<<1];
int head[maxn],cnt[maxn],book[maxn],dis[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void bfs()
{
	queue<pair<int,int> >q;
	q.push(make_pair(1,1));
	book[1]=1;
	cnt[1]=1;
	while(q.size())
	{
		int u=q.front().first;
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(book[v]==0)
			{
				dis[v]=dis[u]+1;
				cnt[v]+=cnt[u];
				cnt[v]%=mod;
				q.push(make_pair(v,dis[v]));
				book[v]=1;
			}
			else if(book[v]==1&&dis[v]==dis[u]+1)
			{
				cnt[v]+=cnt[u];
				cnt[v]%=mod;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u!=v)
		{
			add(u,v);
			add(v,u);
		}
	}
	bfs();
	for(int i=1;i<=n;i++)
	printf("%d\n",cnt[i]%mod);
	return 0;
}
