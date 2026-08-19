#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt_edge,k,ans;
const int maxn=1e6+10;
struct node{
	int to,next,wt;
}edge[maxn];
struct tire{
	int son[2];
}tree[maxn];
int head[maxn],w[maxn];
void add_edge(int u,int v,int w)
{
	edge[++cnt_edge]={v,head[u],w};
	head[u]=cnt_edge;
}
void dfs(int u,int f,int wt)
{
	w[u]=wt;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f)
			dfs(v,u,wt^edge[i].wt);
	}
}
void add(int x)
{
	int id=0;
	for(int i=31;i>=0;i--){
		if(tree[id].son[1&(x>>i)]==0)
			tree[id].son[1&(x>>i)]=++k;
		id=tree[id].son[1&(x>>i)];
	}
}
int query(int x)
{
	int id=0,ans=0;
	for(int i=31;i>=0;i--){
		if(tree[id].son[1^(1&(x>>i))])
		id=tree[id].son[1^(1&(x>>i))],ans+=1<<i;
		else id=tree[id].son[1&(x>>i)]; 
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,_w;i<n;i++){
		scanf("%d%d%d",&u,&v,&_w);
		add_edge(u,v,_w);
		add_edge(v,u,_w);
	}
	dfs(1,1,0);
	for(int i=1;i<=n;i++)
	add(w[i]),ans=max(ans,query(w[i]));
	printf("%d",ans);
	return 0;
}
