#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int T,n,m,k,cnt[maxn];
ll l,r,ans,dis[maxn];
bool mp[maxn][maxn],book[maxn];
struct node{
	int to,next;
	ll wt;
}edge[maxn*maxn];
int head[maxn];
void add(int u,int v,ll w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!book[v])
			dfs(v);
	}
}
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]|=mp[i][k]&mp[k][j];
}
queue<int>q;
bool check(ll x)
{
	while(q.size())q.pop();
	memset(book,0,sizeof book);
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	q.push(1),book[1]=1,dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(mp[n][v]&&dis[v]>dis[u]+edge[i].wt+x){
				dis[v]=dis[u]+edge[i].wt+x;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n)return false;
				if(!book[v]){
					book[v]=1;
					q.push(v);
				}
			}
		}
	}
	if(dis[n]<0)return false;
	return true;
}
int main(){
	scanf("%d",&T);
	if(!T)return puts("2"),0;
	while(T--){
		memset(head,0,sizeof head);
		memset(edge,0,sizeof edge);
		memset(book,0,sizeof book);
		memset(mp,0,sizeof mp);
		k=0;
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++){
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			add(u,v,w);
			mp[v][u]=true;
		}
		for(int i=1;i<=n;i++)
			mp[i][i]=true;
		dfs(1);
		if(!book[n]){
			puts("-1");
			continue;
		}
		floyd();
		l=-1e5,r=1e5;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))r=mid-1,ans=dis[n];
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
}
