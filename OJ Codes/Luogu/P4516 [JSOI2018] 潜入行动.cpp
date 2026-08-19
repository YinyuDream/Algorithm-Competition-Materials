#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int f[maxn][maxn][3];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			dfs(v,u);
			
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	return 0;
}
