#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1500;
int n,m;
int dis[maxn];
struct node{
	int to,next,weight;
}edge[maxn*40];
int head[maxn];
void add(int u,int v,int w,int k)
{
	edge[k].to=v;
	edge[k].next=head[u];
	edge[k].weight=w;
	head[u]=k;
}
int dfs(int x)
{
	int tmp=-1;
	if(x==n)return 0;
	if(dis[x]!=-1)return dis[x];
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		int disv=dfs(v);
		if(disv!=-1)tmp=max(tmp,dfs(v)+edge[i].weight);
	}
	return dis[x]=tmp;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add(a,b,v,i);
	}
	memset(dis,-1,sizeof dis);
	dis[n]=0;
	printf("%d",dfs(1));
	return 0;
}
