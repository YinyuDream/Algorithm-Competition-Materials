#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10,inf=0x3f3f3f3f;
int n,m,qd,zd,s,l,r,k,ans;
int a[maxn];
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
int dis[maxn],book[maxn];
bool dijkstra(int cost)
{
	if(a[qd]>cost)return false;
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f,sizeof dis);
	memset(book,0,sizeof book);
	dis[qd]=0;
	q.push(make_pair(0,qd));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]&&a[v]<=cost&&dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return dis[zd]<=s;
}
int main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&qd,&zd,&s);
	for(int i=1;i<=n;i++)	
		scanf("%d",&a[i]),r=max(r,a[i]);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	if(!dijkstra(r))return puts("-1"),0;
	while(l<=r){
		int mid=(l+r)/2;
		if(dijkstra(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
