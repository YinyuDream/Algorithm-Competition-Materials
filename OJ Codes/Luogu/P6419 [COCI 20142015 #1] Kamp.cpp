#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int to,next,wt;
}edge[maxn*2];
int head[maxn],p[maxn],person[maxn],size[maxn],deep[maxn],sum[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=person[u];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+edge[i].wt;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
		person[p[i]]++;
	}
	dfs(1,1);
	for(int i=1;i<=m;i++)
		sum[1]+=deep[p[i]];
	printf("%d\n",sum[1]);
	return 0;
}
