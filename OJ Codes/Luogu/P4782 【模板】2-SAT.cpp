#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=2e6+10;
int n,m,k,cnt;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int dfn[maxn],low[maxn],belong[maxn],in[maxn],top;
stack<int>st;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	in[u]=1;
	st.push(u);
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
	if(low[u]==dfn[u]){
		cnt++;
		while(st.top()!=u){
			belong[st.top()]=cnt;
			in[st.top()]=0;
			st.pop();
		}
		belong[st.top()]=cnt;
		in[st.top()]=0;
		st.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		add(a+(b^1)*n,c+d*n);
		add(c+(d^1)*n,a+b*n);
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(belong[i]==belong[i+n])
		{
			puts("IMPOSSIBLE");
			return 0;
		}
	puts("POSSIBLE");
	for(int i=1;i<=n;i++){
		printf("%d ",belong[i]>belong[i+n]?1:0);
	}
	return 0;
}
