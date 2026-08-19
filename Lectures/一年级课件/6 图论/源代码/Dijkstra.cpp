#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,s,k;
struct Edge{
	int to,next,wt;
}edge[maxn];
int head[maxn];
struct node{
	int id,d;
	node(int id1,int d1){
		id=id1;d=d1;
	}
	bool friend operator<(node a,node b){
		return a.d>b.d;
	}
};
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int book[maxn],dis[maxn];
priority_queue<node>q;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	memset(dis,0x7f,sizeof dis);
	dis[s]=0;q.push(node(s,0));
	for(int j=1;j<n;j++)
	{
		while(book[q.top().id]==1)q.pop();
		node p=q.top();
		book[p.id]=1;
		q.pop();
		for(int i=head[p.id];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dis[v]>dis[p.id]+edge[i].wt&&book[v]==0)
			{
				dis[v]=dis[p.id]+edge[i].wt;
				q.push(node(v,dis[v]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d ",dis[i]);
	return 0;
}
