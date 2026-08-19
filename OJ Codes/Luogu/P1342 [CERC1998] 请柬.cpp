#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,k1,k2;
ll ans;
struct node{
	int to,next;
	ll weight;
}edge[maxn],edge2[maxn];
int head[maxn],head2[maxn];
ll dis[maxn],dis2[maxn];
void add(int u,int v,ll w,int opt)
{
	if(opt==1)
	edge[++k1]={v,head[u],w},
	head[u]=k1;
	else
	edge2[++k2]={v,head2[u],w},
	head2[u]=k2;
}
struct node2{
	int id;ll d;
	node2(){}
	node2(int Id,ll D){id=Id,d=D;}
	bool operator<(const node2 &a)const{
		return d>a.d;
	}
};
priority_queue<node2>q;
int book[maxn];
void dijkstra()
{
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(node2(1,0));
	for(int i=1;i<=n;i++)
	{
		while(book[q.top().id])q.pop();
		int u=q.top().id;
		book[u]=1;
		q.pop();
		for(int j=head[u];j;j=edge[j].next)
		{
			int v=edge[j].to;
			if(dis[v]>dis[u]+edge[j].weight)
			{
				dis[v]=dis[u]+edge[j].weight;
				q.push(node2(v,dis[v]));
			}
		}
	}
	while(q.size())q.pop();
	memset(dis2,0x3f,sizeof dis2);
	memset(book,0,sizeof book);
	dis2[1]=0;
	q.push(node2(1,0));
	for(int i=1;i<=n-1;i++)
	{
		while(book[q.top().id])q.pop();
		int u=q.top().id;
		book[u]=1;
		q.pop();
		for(int i=head2[u];i;i=edge2[i].next)
		{
			int v=edge2[i].to;
			if(dis2[v]>dis2[u]+edge2[i].weight)
			{
				dis2[v]=dis2[u]+edge2[i].weight;
				q.push(node2(v,dis2[v]));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w,1);
		add(v,u,w,2);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		ans+=dis[i]+dis2[i];
	printf("%lld",ans);
	return 0;
}
