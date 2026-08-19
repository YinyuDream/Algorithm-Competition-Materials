#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const ll inf=0x7f7f7f7f7f7f7f7fll;
int n,m,s,t,k;
ll ans;
struct node{
	int to,next;
	ll wt;
}edge[maxn*2];
int head[maxn];
void add(int u,int v,ll w)
{
	edge[k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k++;
}
int dis[maxn],now[maxn];
queue<int>q;
bool bfs()
{
	memset(dis,-1,sizeof dis);
	dis[s]=0;
	now[s]=head[s];
	q.push(s);
	while(!q.empty()){
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
ll dfs(int u,ll flo)
{
	if(u==t)return flo;
	ll delta=flo;
	for(int i=now[u];i!=-1;i=edge[i].next){
		now[u]=i;
		int v=edge[i].to;
		if(dis[v]==dis[u]+1&&edge[i].wt){
			ll d=dfs(v,min(delta,edge[i].wt));
			edge[i].wt-=d;
			edge[i^1].wt+=d;
			delta-=d;
		}
		if(!delta)break;
	}
	return flo-delta;
}
int main(){
	memset(head,-1,sizeof head);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1,u,v;i<=m;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,0ll);
	}
	while(bfs())ans+=dfs(s,inf);
	printf("%lld",ans);
	return 0;
}