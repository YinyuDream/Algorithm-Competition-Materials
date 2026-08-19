#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e3+10;
int n,m,s,t,k,cnt;
int dis[maxn];
int book[maxn];
struct node{
	int to,next,weight;
}edge[maxn*100],edge2[maxn*100];
int head[maxn],head2[maxn];
void adde(int u,int v,int w,int k,int mode)
{
	if(mode==0)
	edge[k].to=v,
	edge[k].next=head[u],
	edge[k].weight=w,
	head[u]=k;
	else
	edge2[k].to=v,
	edge2[k].next=head2[u],
	edge2[k].weight=w,
	head2[u]=k;
}
struct node2{
	int w,id;
	friend bool operator<(node2 a,node2 b){
		return a.w>b.w;
	}
};
priority_queue<node2>q;
void dijkstra()
{
	memset(dis,0x3f,sizeof dis),dis[1]=0;
	node2 tmp;
	tmp.id=1,tmp.w=0;
	q.push(tmp);
	for(int i=1;i<n;i++)
	{	
		if(book[q.top().id])q.pop();
		tmp=q.top(),q.pop(),book[tmp.id]=true;
		for(int i=head2[tmp.id];i;i=edge2[i].next)
		{
			int v=edge2[i].to;
			if(dis[v]>dis[tmp.id]+edge2[i].weight)
			{
				dis[v]=dis[tmp.id]+edge2[i].weight;
				if(book[v]==0)
				{
					node2 no;
					no.id=v,no.w=dis[v],q.push(no);
				}
			}
		}
	}
}
struct node3{
	int d,g,id;
	friend bool operator<(node3 a,node3 b){
		return a.d+a.g>b.d+b.g;
	}
};
priority_queue<node3>p;
void A_star()
{	
	memset(book,0,sizeof book);
	node3 tmp;
	tmp.id=n,tmp.d=0,tmp.g=dis[n];
	p.push(tmp);
	while(p.size())
	{
		node3 tp=p.top();
		p.pop();
		book[tp.id]++;
		if(book[tp.id]>k)continue;
		if(book[1]<=k&&tp.id==1)printf("%d\n",tp.d);
		for(int i=head[tp.id];i;i=edge[i].next)
		{
			int v=edge[i].to;
			node3 no;
			no.d=tp.d+edge[i].weight;
			no.g=dis[v];
			no.id=v;
			p.push(no);
		}
	}
	for(int i=1;i<=k-book[1];i++)printf("-1\n");
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),adde(u,v,w,i,0),adde(v,u,w,i,1);
	dijkstra();
	A_star();
	return 0;
}