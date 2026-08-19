#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int k,T;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int dfn[maxn],low[maxn],in[maxn],pos[maxn],cnt,top;
stack<int>s;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	in[u]=1;
	s.push(u);
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
		while(s.top()!=u){
			pos[s.top()]=cnt;
			in[s.top()]=0;
			s.pop();
		}
		pos[s.top()]=cnt;
		in[s.top()]=0;
		s.pop();
	}
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		cnt=top=k=0;
		int n,m,flag=0;
		memset(edge,0,sizeof edge);
		memset(head,0,sizeof head);
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(pos,0,sizeof pos);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int a,b,c,d;
			char x,y;
			scanf("\n%c%d %c%d",&x,&a,&y,&c);
			b=(x=='h'?0:1);
			d=(y=='h'?0:1);
			add(a+(b^1)*n,c+d*n);
			add(c+(d^1)*n,a+b*n);
		}
		for(int i=1;i<=n*2;i++)
				if(!dfn[i])
					tarjan(i);
		for(int i=1;i<=n;i++){
			if(pos[i]==pos[i+n]){
				flag=true;
				break;
			}
		}
		printf("%s\n",flag?"BAD":"GOOD");
	}
	return 0;
}
