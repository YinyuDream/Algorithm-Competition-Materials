#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm=50000+10;
int n,m,q;
int min(int a,int b){ return a<=b?a:b;}
struct e{
	int u,v,w;
} edges[maxm];
struct node{
	int to,w,next;
} edge[maxm];
int father[maxm];
int head[maxm],k=0;
int read()//读入优化
{
    int ret=0,flag=1;char ch=getchar();  
    while (ch<'0'||ch>'9') {if (ch=='-') flag=-1;ch=getchar();}  
    while (ch>='0' && ch<='9') {ret=ret*10+ch-'0';ch=getchar();}  
    return ret*flag;
}
bool cmp(e a,e b){
	if(a.u!=b.u) return a.u<b.u;
	else if(a.v!=b.v) return a.v<b.v;
	else a.w<b.w;
}
bool cmp2(e a,e b){return a.w>b.w;}
int find(int x)
{
	return x==father[x]?x:father[x]=find(father[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	father[fx]=fy;
}
void add(int u,int v,int w)
{
	edge[++k].to=v;edge[k].w=w;
	edge[k].next=head[u];head[u]=k;
}
void kruskal()
{
	int t=0;
	for(int i=1;i<=m;i++)
	{
		if(find(edges[i].u)!=find(edges[i].v))
		{
			merge(edges[i].u,edges[i].v);
			add(edges[i].u,edges[i].v,edges[i].w);
			add(edges[i].v,edges[i].u,edges[i].w);
			t++;if(t>=n-1) return ;
		}
	}
}
bool visit[maxm];
int fa[maxm][18],dp[maxm][18],deep[maxm];
void dfs(int x){
	visit[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++){//倍增预处理 
		fa[x][i]=fa[fa[x][i-1]][i-1];
		dp[x][i]=min(dp[x][i-1],dp[fa[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=edge[i].next){//dfs遍历枚举 
		int v=edge[i].to;
		if(!visit[v]){
			fa[v][0]=x; dp[v][0]=edge[i].w;
			deep[v]=deep[x]+1; dfs(v);
		} 
	}
}
int lca(int x,int y){//求解(x,y)的LCA 
	//1:把(x,y)调整到同一高度 
	if(deep[x]<deep[y]) swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;(1<<i)<=t;i++) if((1<<i)&t) x=fa[x][i];
	if(x==y) return x;//同一条链上 
	//2:找(x,y)的最近公共祖先
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		} 
	}
	return fa[x][0];
}
int ask(int x,int f){
	int minm=0x7f7f7f;
	int t=deep[x]-deep[f];
	for(int i=0;(1<<i)<=t;i++){
		if((1<<i)&t){
			minm=min(minm,dp[x][i]);
			x=fa[x][i];	
		}
	}
	return minm;	
}
int main()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edges[i].u=u;edges[i].v=v;edges[i].w=w;
	}
	sort(edges+1,edges+m+1,cmp2);
	for(int i=1;i<=n;i++) father[i]=i;
	kruskal();
	for(int i=1;i<=n;i++) if(!visit[i]) dfs(i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v)) {printf("-1\n");continue;}
		int t=lca(u,v);
		printf("%d\n",min(ask(u,t),ask(v,t)));
	}
	return 0;
}
