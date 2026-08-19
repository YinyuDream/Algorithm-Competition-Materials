#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int deg[maxn],ans[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			q.push(i),
			ans[i]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			ans[v]=max(ans[v],ans[u]);
			deg[v]--;
			if(deg[v]==0){
				ans[v]++;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
