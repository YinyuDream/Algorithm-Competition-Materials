#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1500;
const int inf=9999999;
int n,V,E;
int cow[N];
struct node
{
	int to,next,w;
}edge[2*N];
int head[880];
bool book[880];
int dis[880];
queue<int>q;
int cnt;
void build(int u,int v,int w)
{
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void spfa(int s)
{
	int k;
	for(int i=1;i<=V;i++)dis[i]=inf;
	memset(book,false,sizeof(book));
	dis[s]=0;book[s]=1;q.push(s);
	while(!q.empty())
	{
		k=q.front();
		for(int i=head[k];i>0;i=edge[i].next)
		{ 
			if(dis[edge[i].to]>dis[k]+edge[i].w)
			{
				dis[edge[i].to]=dis[k]+edge[i].w;
				if(!book[edge[i].to])
				{
					book[edge[i].to]=1;
					q.push(edge[i].to);
				}
				//如果被松弛的点已经在队列，就不用重复入队了。 
			}
		}
		book[k]=0;//必须取消标记，有可能通过其他点松弛k。否则k不能入队 
		q.pop();//弹出，否则每次对首元素都是它。 
	}
}
int main()
{
	int t1,t2,t3;
	scanf("%d%d%d",&n,&V,&E);
	for(int i=1;i<=n;i++)scanf("%d",&cow[i]);
	for(int i=1;i<=E;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		build(t1,t2,t3);
		build(t2,t1,t3);
	}
	int sum,ans=inf;
	for(int i=1;i<=V;i++)//枚举每个点当起点， 
	{
		sum=0;
		spfa(i);//求出i点到周围所有点的最短路。 
		for(int j=1;j<=n;j++)	sum+=dis[cow[j]];
		if(ans>sum)ans=sum;
	}
	printf("%d",ans);
	return 0;
}
