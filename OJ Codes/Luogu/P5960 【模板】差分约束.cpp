#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next,weight;
}edge[maxn];
int head[maxn],dis[maxn],book[maxn],cnt[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].weight=w;
	head[u]=k;
}
void spfa()
{
	queue<int>q;
	memset(dis,0x7f,sizeof dis);
	dis[0]=0;q.push(0);book[0]=1;cnt[0]=1;
	while(q.size())
	{
		int p=q.front();
		q.pop();
		book[p]=0;
		for(int i=head[p];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[p]+edge[i].weight)
			{
				dis[v]=dis[p]+edge[i].weight;
				if(++cnt[v]==n)
				puts("NO"),exit(0);
				q.push(v);
				book[v]=1;
			}
		}
	} 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++)
	{
		add(0,i,0);
	}
	spfa();
	for(int i=1;i<=n;i++)
	printf("%d ",dis[i]);
	return 0;
}
