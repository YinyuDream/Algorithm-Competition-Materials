#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int a[maxn],weight[maxn],s[maxn];
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
int dis[maxn],book[maxn];
void dijkstra()
{
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]&&dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	//freopen("holes.in","r",stdin);
	//freopen("holes.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)	
		scanf("%d",&weight[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		int delta=abs(weight[v]-weight[u]);
		if(a[u]==a[v])add(u,v+n,w),add(u+n,v,w);
		else if(a[u]==1&&a[v]==0)add(u,v+n,w+delta),add(u+n,v,max(w-delta,0));
		else add(u,v+n,max(w-delta,0)),add(u+n,v,w+delta);
	}
	for(int i=1;i<=n;i++)
		if(!a[i]){
			add(i,i+n,0);
			add(i+n,i,s[i]);
		}else{
			add(i,i+n,s[i]);
			add(i+n,i,0);
		}
	dijkstra();
	printf("%d",min(dis[n],dis[n*2]));
	return 0;
}