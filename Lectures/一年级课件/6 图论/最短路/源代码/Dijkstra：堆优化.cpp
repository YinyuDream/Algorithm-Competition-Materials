#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=100000+10;
int book[maxn],dis[maxn];

int head[maxn];//建图 
struct node
{
	int to,next,w;
	
};
node edge[maxn*2];
int k=0;
void adde(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].w=w;
	edge[k].next=head[u];
	head[u]=k;
}

struct node2//优先队列需要的结构体 
{
	int k;//入队点的编号 
	int dis;//k点的dis==dis[k] 
	friend bool operator <(node2 a,node2 b)//重载<符号，改变优先级，dis小的在队首； 
	{
		return a.dis>b.dis;
	}
};
priority_queue<node2> q;



int n,m,s;
int main()
{
	//freopen("testdata.in","r",stdin);
	scanf("%d%d%d",&n,&m,&s);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);//健图 
		adde(u,v,w);
	}
	memset(dis,0x3f,sizeof(dis));//初始化最短路径无穷大 
	dis[s]=0;
	
	node2 no;
	no.k=s;no.dis=0;q.push(no);//起点入队 
	
	for(int i=1;i<=n-1;i++)
	{
		
		while(book[q.top().k]==1)q.pop();//已经标记的点（最小距离已确定），不能重复松弛周围的点 
		u=q.top().k;
		book[u]=1;//取对首的k值，dis[u]在队列中最小。可标记。 
		q.pop();//对首值已经取出，无用了。弹出 
		for(int j=head[u];j>0;j=edge[j].next)//枚举u点周围有边相连的点。 
		{
			v=edge[j].to;w=edge[j].w;
			if(book[v]==0 && dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;//如果松弛成功，则被松弛的点入队， 
				no.k=v;no.dis=dis[v];
				q.push(no);	//注意，这里可能发生同一个点多次入队的情况。 
			}
		}
	}
	
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
}
