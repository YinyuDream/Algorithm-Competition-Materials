#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
struct node
{
	int to,next;
} edge[maxn<<1];
int head[maxn],n,m,a[maxn],f[maxn][maxn][2],k=0,ls[maxn],rs[maxn],visit[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void pre(int x,int fa)
{
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		if(!visit[x]) ls[x]=edge[i].to;
		else rs[visit[x]]=edge[i].to;
		visit[x]=edge[i].to;
		pre(edge[i].to,x);
	}
}
void dfs(int x)
{
	if(ls[x]) dfs(ls[x]);
	if(rs[x]) dfs(rs[x]);
	for(int i=0;i<=m;i++) f[x][i][0]=max(f[x][i][0],f[ls[x]][i][0]);
	for(int i=0;i<=m;i++) f[x][i][0]=max(f[x][i][0],f[rs[x]][i][0]);
	for(int i=0;i<=m;i++) f[x][i][1]=max(f[x][i][1],max(f[ls[x]][i][0],f[ls[x]][i][1])+max(f[rs[x]][m-i-1][0],f[rs[x]][m-i-1][1])+a[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,aa,bb;i<n;i++)
	{
		scanf("%d%d",&aa,&bb);
		add(aa,bb);add(bb,aa);
	}
	pre(1,1);
	dfs(1);
	printf("%d\n",max(f[1][m][0],f[1][m][1]));
	return 0;
}
