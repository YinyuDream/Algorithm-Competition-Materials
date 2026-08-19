#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,s,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],book[maxn],dis[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
priority_queue<pair<int,int> >q;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),add(u,v,w);
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
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]!=0x3f3f3f3f?dis[i]:0x7f7f7f7f);
	return 0;
}
