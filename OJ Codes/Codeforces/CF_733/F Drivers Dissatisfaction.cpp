#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,min_tree,k,s,ans_edge,ans;
int w[maxn],c[maxn];
struct Edge{int u,v,w,c,flag,id;}e[maxn];
struct node{int to,next,weight,id;}edge[maxn*2];
int head[maxn],fa[maxn],father[maxn][20],max_val[maxn][20],depth[maxn],g[maxn][20];
void add_edge(int u,int v,int w,int id)
{
	edge[++k]={v,head[u],w,id};
	head[u]=k;
}
bool cmp(Edge a,Edge b){return a.w<b.w;}
bool cmp2(Edge a,Edge b){return a.id<b.id;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int u,int f)
{
	for(int i=1;(1<<i)<=depth[u];i++)
	{
		father[u][i]=father[father[u][i-1]][i-1];
		max_val[u][i]=max_val[u][i-1];
		g[u][i]=g[u][i-1];
		if(max_val[u][i]<max_val[father[u][i-1]][i-1])
		max_val[u][i]=max_val[father[u][i-1]][i-1],
		g[u][i]=g[father[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			depth[v]=depth[u]+1;
			father[v][0]=u;
			max_val[v][0]=edge[i].weight;
			g[v][0]=edge[i].id;
			dfs(v,u);
		}
	}
}
pair<int,int> query(int u,int v)
{
	int val=0,edge_id=0;
	if(depth[u]<depth[v])swap(u,v);
	int t=depth[u]-depth[v];
	for(int i=0;i<20;i++)
		if((1<<i)&t)
		{
			if(val<max_val[u][i])
				val=max_val[u][i],
				edge_id=g[u][i];
			u=father[u][i];
		}
	if(u==v)return make_pair(val,edge_id);
	for(int i=19;i>=0;i--)
		if(father[u][i]!=father[v][i])
		{
			if(val<max_val[u][i]){
				val=max_val[u][i];
				edge_id=g[u][i];
			}
			if(val<max_val[v][i]){
				val=max_val[v][i];
				edge_id=g[v][i];
			}
			u=father[u][i];
			v=father[v][i];
		}
	if(val<max_val[u][0]){
		val=max_val[u][0];
		edge_id=g[u][0];
	}
	if(val<max_val[v][0]){
		val=max_val[v][0];
		edge_id=g[v][0];
	}
	return make_pair(val,edge_id);
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++)
	scanf("%lld",&c[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		e[i]={u,v,w[i],c[i],0,i};
	}
	scanf("%lld",&s);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
		{
			add_edge(e[i].u,e[i].v,e[i].w,e[i].id);
			add_edge(e[i].v,e[i].u,e[i].w,e[i].id);
			min_tree+=e[i].w;
			fa[fx]=fy;
			e[i].flag=1;
		}
	}
	dfs(1,1);
	ans=min_tree;
	for(int i=1;i<=m;i++)
	{
		if(e[i].flag==1){
			if(ans>min_tree-s/e[i].c){
				ans=min_tree-s/e[i].c;
				ans_edge=e[i].id;
			}
		}else{
			int t=query(e[i].u,e[i].v).first;
			if(ans>min_tree+e[i].w-s/e[i].c-t){
				ans=min_tree+e[i].w-s/e[i].c-t;
				ans_edge=e[i].id;
			}
		}
	}
	printf("%lld\n",ans);
	sort(e+1,e+m+1,cmp2);
	bool flag=false;
	for(int i=1;i<=m;i++)
	{
		if(ans_edge==i&&e[i].flag==1){
			flag=true;
			break;
		}
	}
	if(flag){
		for(int i=1;i<=m;i++)
			if(e[i].flag)
				printf("%lld %lld\n",i,ans_edge!=i?e[i].w:e[i].w-s/e[i].c);
	}else{
		int t=query(e[ans_edge].u,e[ans_edge].v).second;
		for(int i=1;i<=m;i++)
			if(e[i].flag&&t!=i)
				printf("%lld %lld\n",i,e[i].w);
			else if(e[i].flag==0&&ans_edge==i)
				printf("%lld %lld\n",i,e[i].w-s/e[i].c);
	}
	return 0;
}
