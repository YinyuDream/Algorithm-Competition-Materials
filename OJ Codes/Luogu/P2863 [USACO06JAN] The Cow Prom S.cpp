#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],cnt[maxn],size[maxn],low[maxn],dfn[maxn],in_stack[maxn],top,tot,ans;
int n,m,k;
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
stack<int>s;
void tarjan(int u)
{
	low[u]=dfn[u]=++top;
	s.push(u);
	in_stack[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in_stack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		tot++;
		while(s.top()!=u){
			size[tot]++;
			in_stack[s.top()]=0;
			s.pop();
		}
		size[tot]++;
		in_stack[s.top()]=0;
		s.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=tot;i++)
		if(size[i]>1)
			ans++;
	printf("%d",ans);
	return 0;
}
