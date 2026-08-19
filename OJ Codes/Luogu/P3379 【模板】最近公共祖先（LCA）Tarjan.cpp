#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,m,s,k_tree,k_ask;
int head_tree[maxn],head_ask[maxn],ans[maxn],book[maxn],fa[maxn];
struct node{
	int to,next;
}edge_tree[2*maxn],edge_ask[2*maxn];
struct function{
	void add_tree(int u,int v){
	edge_tree[++k_tree].to=v,edge_tree[k_tree].next=head_tree[u],head_tree[u]=k_tree;
	}
	void add_ask(int u,int v){
	edge_ask[++k_ask].to=v,edge_ask[k_ask].next=head_ask[u],head_ask[u]=k_ask;
	}
}a;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void Tarjan_Lca(int x){
	book[x]=true;
	for(int i=head_tree[x];i;i=edge_tree[i].next)
		if(!book[edge_tree[i].to])
			Tarjan_Lca(edge_tree[i].to),fa[edge_tree[i].to]=x;
	for(int i=head_ask[x];i;i=edge_ask[i].next)
		if(book[edge_ask[i].to])
			ans[(i+1)/2]=find(edge_ask[i].to);
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	int u,v;
	for(int i=1;i<=n-1;i++)scanf("%d%d",&u,&v),a.add_tree(u,v),a.add_tree(v,u);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),a.add_ask(u,v),a.add_ask(v,u);
	Tarjan_Lca(s);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
