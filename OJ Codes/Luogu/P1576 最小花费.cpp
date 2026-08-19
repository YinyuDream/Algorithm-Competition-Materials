#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=2e5+10;
int n,m,qd,zd;
int head[maxn];
double dis[maxn];
bool book[maxn];
struct node{
	int to,next;
	double w;
}edge[50*maxn];
struct node2{
	double w;
	int id;
	friend bool operator <(node2 x,node2 y){
		return x.w<y.w;
	}
}point[maxn];
priority_queue<node2>q;
int k=0;
void add(int u,int v,double w)
{
#define i k
	edge[++i].to=v;
	edge[i].next=head[u];
	edge[i].w=w;
	head[u]=i;
#undef i
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		double w;
		scanf("%d%d%lf",&u,&v,&w);
		w=(100-w)/100;
		add(u,v,w);
		add(v,u,w);
	}
	scanf("%d%d",&qd,&zd);
	memset(dis,-0x3f,sizeof(dis));
	dis[qd]=1;
	node2 a;
	a.id=qd;a.w=1;
	q.push(a);
	for(int i=1;i<=n-1;i++)
	{
		while(book[q.top().id])q.pop();
		int u=q.top().id;
		book[u]=1;
		if(u==zd)
		{
		    printf("%.8f",100/dis[u]);exit(0);
		}
		q.pop();
		for(int j=head[u];j>0;j=edge[j].next)
		{
			int v=edge[j].to;double w=edge[j].w;
			if(book[v]==0&&dis[v]<dis[u]*w)
			{
				dis[v]=dis[u]*w;
				node2 b;
				b.id=v;b.w=dis[v];
				q.push(b);
			}
		}
	}
	printf("%.8f",100/dis[zd]);
	return 0;
}
