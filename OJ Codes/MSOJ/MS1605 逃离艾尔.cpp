#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int n,m,k,q,t,w,ans;
int a[maxn],fa[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],size[maxn],dis[maxn],now[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
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
	return dis[t]!=-1;
}
int dfs(int u,int flo)
{
	if(u==t)return flo;
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
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		size[i]=a[i];
		fa[i]=i;
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int fx=find(u),fy=find(v);
		if(fx!=fy)fa[fx]=fy,size[fy]+=size[fx],size[fx]=0;
	}
	for(int i=1,u,v,w;i<=q;i++){
		scanf("%d%d%d",&u,&v,&w);
		int fx=find(u),fy=find(v);
		if(fx!=fy)add(fx,fy,w),add(fy,fx,0);
	}
	t=find(1);
	for(int i=1;i<=n;i++)
		if(size[i])
			add(0,i,size[i]),add(i,0,0);
	while(bfs())ans+=dfs(0,inf);
	printf("%d",ans);
	return 0;
}