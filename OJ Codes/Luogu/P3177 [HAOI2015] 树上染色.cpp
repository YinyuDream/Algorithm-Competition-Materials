#include<cstdio>
using namespace std;
const int maxn=2e3+10;
int n,k;
struct node{
	int to,next,weight;
}edge[maxn];
int head[maxn],d[maxn];
int f[maxn][maxn][2],f[maxn][maxn][2];
void dfs(int u,int f,int dep)
{	
	d[u]=dep;
	for(int i=head[u];u;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		dfs(v,u,dep+edge[i].weight);
	}
}
void f(int u,int v)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		dfS(v,u);
		for(int j=0;j<=m;j++){
			for(int k=m;k>=0;k--){
				
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	f(1,1);
	printf("%d\n",f[1][m][0/1]);
	return 0;
}
