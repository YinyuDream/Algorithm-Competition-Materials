#include<cstdio>
#include<stack>
using namespace std;
const int maxn=1e6+10;
int n,ans=0x7f7f7f7f,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int top,tot,dfn[maxn],low[maxn],news[maxn],cnt[maxn],in[maxn];
stack<int>s;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	s.push(u);
	in[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		tot++;
		while(s.top()!=u)
		{
			news[s.top()]=tot;
			cnt[tot]++;
			in[s.top()]=0;
			s.pop();
		}
		news[s.top()]=tot;
		cnt[tot]++;
		in[s.top()]=0;
		s.pop();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(i,v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=tot;i++)
		if(cnt[i]!=1)
			ans=min(ans,cnt[i]);
	printf("%d",ans);
	return 0;
}
