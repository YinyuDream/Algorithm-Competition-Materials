#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k=1;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int t,top,low[maxn],dfn[maxn],vis[maxn];
pair<int,int>ans[maxn];
void dfs(int u,int from)
{
	low[u]=dfn[u]=++t;
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if((i^1)!=from)
		{
			if(!dfn[v]){
				dfs(v,i);
				low[u]=min(low[u],low[v]);
			}else if(vis[v]==1){
				low[u]=min(low[u],dfn[v]);
			}
		}
	}
	vis[u]=0;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first!=b.first)return a.first<b.first;
	else return a.second<b.second;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(low[i]>dfn[edge[j].to]||low[edge[j].to]>dfn[i])
				if(i<edge[j].to)
					ans[++top]=make_pair(i,edge[j].to);
	sort(ans+1,ans+top+1,cmp);
	for(int i=1;i<=top;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
