#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next;
	long long wt;
}edge[maxn];
int head[maxn],t[maxn];
void add(int u,int v,long long w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
priority_queue<pair<long long,int> >q;
int vis[maxn],book[maxn];
long long dis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		for(int j=1,u;j<=t[i];j++){
			scanf("%d",&u);
			add(u,i,-1);
		}
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v])continue;
			if(edge[i].wt!=-1){
				if(dis[v]>dis[u]+edge[i].wt){
					dis[v]=dis[u]+edge[i].wt;
					if(!t[v])q.push(make_pair(-dis[v],v));
					else vis[v]=1;
				}
			}else{
				t[v]--;
				if(vis[v])dis[v]=max(dis[v],dis[u]);
				if(t[v]==0&&vis[v])q.push(make_pair(-dis[v],v));
			}
		}
	}
	printf("%lld",dis[n]);
	return 0;
}
