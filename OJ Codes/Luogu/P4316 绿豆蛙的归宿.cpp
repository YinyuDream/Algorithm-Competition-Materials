#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],deg[maxn],in[maxn];
double f[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w);
		deg[u]++;
		in[u]++;
	}
	q.push(n);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			f[v]+=(f[u]+edge[i].wt)/deg[v];
			in[v]--;
			if(!in[v])q.push(v);
		}
	}
	printf("%.2f",f[1]);
	return 0;
}
