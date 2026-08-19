#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,s,k,ans;
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
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),add(u,v,w),add(v,u,w);
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		ans+=dis[u];
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>edge[i].wt){
				dis[v]=edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	printf("%d",ans);
	return 0;
}
