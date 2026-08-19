#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int T,n,m,k,p,cnt_edge,ans;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	edge[cnt_edge].wt=w;
	head[u]=cnt_edge;
}
int book[maxn],dis[maxn];
void spfa()
{
	queue<int>q;
	memset(dis,0x3f,sizeof dis);
	memset(book,0,sizeof book);
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				if(!book[v]){
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}
int f[maxn][55];
void work()
{
	memset(f,-1,sizeof f);
	queue<pair<int,int> >q;
	f[1][0]=1;
	q.push(make_pair(1,0));
	while(!q.empty()){
		pii u=q.front();
		q.pop();
		for(int i=head[u.first];i;i=edge[i].next){
			int v=edge[i].to;
			if(u.second+dis[u.first]+edge[i].wt-dis[v]<=k){
				if(f[v][u.second+dis[u.first]+edge[i].wt-dis[v]]==-1){
					f[v][u.second+dis[u.first]+edge[i].wt-dis[v]]=f[u.first][u.second]%p;
					q.push(make_pair(v,u.second+dis[u.first]+edge[i].wt-dis[v]));
				}else{
					f[v][u.second+dis[u.first]+edge[i].wt-dis[v]]+=f[u.first][u.second];
					f[v][u.second+dis[u.first]+edge[i].wt-dis[v]]%=p;
				}
				
			}
		}
	}
}
int main(){
	//freopen("park.in","r",stdin);
	//freopen("park.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof head);
		memset(edge,0,sizeof edge);
		cnt_edge=ans=0;
		scanf("%d%d%d%d",&n,&m,&k,&p);
		for(int i=1,u,v,w;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		spfa();
		work();
		for(int i=0;i<=k;i++)
			if(f[n][i]!=-1)
				ans+=f[n][i];
		printf("%d",ans);
	}
	return 0;
}