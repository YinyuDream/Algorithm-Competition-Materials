#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,p,c,k,ans=0x7f7f7f7f;
int book[maxn],dis[maxn],size[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
priority_queue<pair<int,int> >q;
int dijkstra(int s)
{
	int val=0;
	memset(dis,0x3f,sizeof dis);
	memset(book,0,sizeof book);
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
	for(int i=1;i<=p;i++)
		val+=dis[i]*size[i];
	return val;
}
int main(){
	scanf("%d%d%d",&n,&p,&c);
	for(int i=1,w;i<=n;i++)
		scanf("%d",&w),size[w]++;
	for(int i=1,u,v,w;i<=c;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=p;i++){
		ans=min(ans,dijkstra(i));
	}
	printf("%d",ans);
	return 0;
}
