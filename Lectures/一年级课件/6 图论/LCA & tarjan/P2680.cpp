#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=300000+10;
struct node{
	int to,next,w;
} edge[maxn*2];
int head[maxn];
int n,m,k=0,cnt=0; 
void add(int u,int v,int w){
	edge[++k].to=v;edge[k].w=w;
	edge[k].next=head[u];head[u]=k;
}
int a[maxn],b[maxn],lc[maxn];
int dis[maxn];//dis[i]表示i点到根的距离
int d[maxn];//d[i]表示第i条路径的距离 
int maxt=0;
int deep[maxn],fa[maxn][20],cf[maxn],p[maxn],topre[maxn];
void dfs(int u,int father){
	p[++cnt]=u;
	for(int i=1;(1<<i)<=deep[u];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i>0;i=edge[i].next){
		int v=edge[i].to;
		if(v==father) continue;
		deep[v]=deep[u]+1; fa[v][0]=u;
		dis[v]=dis[u]+edge[i].w;
		topre[v]=edge[i].w;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;(1<<i)<=t;i++) if((1<<i)&t) x=fa[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool check(int ans){//检查是否可行 
	cnt=0;
	memset(cf,0,sizeof(cf));
	for(int i=1;i<=m;i++){
		if(d[i]>ans){
			cf[a[i]]++;cf[b[i]]++; cf[lc[i]]-=2; cnt++;		
		}
	}
	for(int i=n;i>=1;i--){
		cf[fa[p[i]][0]]+=cf[p[i]];
		if(cf[p[i]]==cnt && topre[p[i]]>=maxt-ans) return true;
	}
	return false;
}
int find(int l,int r)
{
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid; else l=mid+1;
	} 
	return l;
}
int main()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dfs(1,1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		a[i]=u;b[i]=v; lc[i]=lca(u,v);
		d[i]=dis[u]+dis[v]-2*dis[lc[i]];
		maxt=max(maxt,d[i]);
	}
	printf("%d\n",find(0,maxt+1));
	return 0;
}
