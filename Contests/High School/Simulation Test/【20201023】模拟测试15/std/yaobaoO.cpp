#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll maxn=1000010;
const ll inf=1e16;
struct nod{
	ll next,to,w;
	nod(){}
	nod(ll _next,ll _to,ll _w){
		next=_next,to=_to;w=_w;
	}
}e[maxn];
struct node{
	ll now,f;
	friend bool operator <(node a,node b){
		return a.f>b.f;
	}
	node(){}
	node(ll _now,ll _f){
		now=_now;f=_f;
	}
};
int head[maxn];ll dis[maxn],S[maxn];
bool vis[maxn];
int n,m,K,k=1;ll ans=inf;
void adde(int u,int v,ll w){
	e[++k]=nod(head[u],v,w);head[u]=k;
}
void dij(ll x){
	priority_queue<node>q;q.push(node(1,0));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	while(!q.empty()){
		int now=q.top().now;q.pop();
		if(vis[now])continue;vis[now]=1;
		for(int i=head[now];i;i=e[i].next){
			if(vis[e[i].to])continue;
			if(dis[e[i].to]>dis[now]+max(e[i].w-x,0ll)){
				dis[e[i].to]=dis[now]+max(e[i].w-x,0ll);
				q.push(node(e[i].to,dis[e[i].to]));
			}
		}
	}ans=min(ans,dis[n]+x*K);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);
		S[i]=w;
	}
	S[0]=0;
	for(ll i=0;i<=m;i++){
		dij(S[i]);
	}printf("%lld\n",ans);
}
