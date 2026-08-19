#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int A,B,C,D,m,n,ans=0x7f7f7f7f,k;
int a[maxn],l[maxn],r[maxn],w[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int dis[maxn],head[maxn],book[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
priority_queue<pair<int,int> >q;
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&A,&B,&C,&D,&n);
	B+=A,C+=B,D+=C,n+=D;
	A++,B++,C++,D++,n++;
	scanf("%d",&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		v++;
		add(u,v,w);
		add(v,u,w);
	}
	dijkstra(A);
	ans=min(ans,dis[b]+dis[d]);
	dijkstra(B);
	ans=min(ans,dis[c]+dis[d]);
	dijkstra(C);
	ans=min(ans,dis[C]+dis[D]);
	printf("%d",ans);
	return 0;
}
