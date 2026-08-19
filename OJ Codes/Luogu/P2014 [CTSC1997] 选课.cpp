#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,k;
int w[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int f[maxn][maxn];//以i为根的子树V==j的最大学分 
void add(int u,int v){
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	f[u][1]=w[u];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		dfs(v);
		for(int j=m+1;j>=1;j--)
			for(int k=0;j-k>0;k++)
				f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int q;
		scanf("%d%d",&q,&w[i]);
		add(q,i);
	}
	dfs(0);
	printf("%d",f[0][m+1]);
	return 0;
}
