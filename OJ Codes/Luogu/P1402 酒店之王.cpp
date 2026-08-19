#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int a,b,c,k,ans;
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
	dis[0]=0;
	q.push(0);
	now[0]=head[0];
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
	return dis[a*2+b+c+1]!=-1;
}
int dfs(int u,int flo)
{
	if(u==a*2+b+c+1)return flo;
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
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1,p;i<=a;i++){
		for(int j=1;j<=b;j++){
			scanf("%d",&p);
			if(p){
				add(j,i+b,1);
				add(i+b,j,0);
			}
		}
	}
	for(int i=1,p;i<=a;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&p);
			if(p){
				add(i+a+b,j+a*2+b,1);
				add(j+a*2+b,i+a+b,0);
			}
		}
	}
	for(int i=1;i<=a;i++)
		add(b+i,a+b+i,1),add(a+b+i,b+i,0);
	for(int i=1;i<=b;i++)
		add(0,i,1),add(i,0,0);
	for(int i=1;i<=c;i++)
		add(a*2+b+i,a*2+b+c+1,1),add(a*2+b+c+1,a*2+b+i,0);
	while(bfs())ans+=dfs(0,inf);
	printf("%d",ans);
	return 0;
}
