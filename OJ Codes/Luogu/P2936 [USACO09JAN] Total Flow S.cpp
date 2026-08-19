#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int n,m,k,ans;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],dis[maxn],vis[maxn],now[maxn];
void add(int u,int v,int w)
{
	edge[k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k++;
}
bool bfs()
{
	queue<int>q;
	memset(dis,-1,sizeof dis);
	dis['A']=0;
	q.push('A');
	now['A']=head['A'];
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]==-1&&edge[i].wt){
				now[v]=head[v];
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis['Z']!=-1;
}
int dfs(int u,int flo)
{
	if(u=='Z')return flo;
	int delta=flo;
	for(int i=now[u];i!=-1;i=edge[i].next){
		now[u]=i;
		int v=edge[i].to;
		if(dis[v]==dis[u]+1&&edge[i].wt){
			int d=dfs(v,min(delta,edge[i].wt));
			edge[i].wt-=d,edge[i^1].wt+=d;
			delta-=d;
			if(!delta)break;
		}
	}
	return flo-delta;
}
int main(){
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for(int i=1,w;i<=n;i++){
		char u,v;
		scanf("\n%c %c %d",&u,&v,&w);
		add(u,v,w);
		add(v,u,0);
	}
	while(bfs())ans+=dfs('A',inf);
	printf("%d",ans);
	return 0;
}
