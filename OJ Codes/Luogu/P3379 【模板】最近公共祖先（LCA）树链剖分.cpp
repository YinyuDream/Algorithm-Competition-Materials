#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,s,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int fa[maxn],top[maxn],deep[maxn],size[maxn],son[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs1(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v]=u;
			deep[v]=deep[u]+1;
			dfs1(v,u);
			size[u]+=size[v];
			if(size[v]>size[son[u]]){
				son[u]=v;
			}
		}
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	if(son[u]){
		dfs2(son[u],tp);
	}
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u]){
			dfs2(v,v);
		}
	}
}
int query(int u,int v)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]>deep[top[v]]){
			u=fa[top[u]];
		}else{
			v=fa[top[v]];
		}
	}
	return deep[u]<deep[v]?u:v;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs1(s,s);
	dfs2(s,s);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",query(u,v));
	}
	return 0;
}
