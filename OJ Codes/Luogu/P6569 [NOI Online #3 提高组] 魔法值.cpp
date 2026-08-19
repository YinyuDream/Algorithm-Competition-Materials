#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e2+10;
int n,m,q,k;
int a[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn],val[maxn][maxn],book[maxn];//val:第i天j号节点的值 
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int d)
{
	book[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		val[d][u]^=val[d-1][v];
		if(book[v]==0)
		dfs(v,d);
	}
}
int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",&val[0][i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=q;i++)
	scanf("%d",&a[i]);
	if(m==n*(n-1)/2){
		val[0][1]=0;
		for(int i=2;i<=n;i++)
		val[0][1]^=val[0][i];
		for(int i=1;i<=q;i++)
		printf("%d \n",val[0][1]);
		return 0;
	}
	/*for(int i=1;i<maxn;i++)
	memset(book,0,sizeof book),dfs(1,i);
	for(int i=1;i<=q;i++)
	printf("%d\n",val[a[i]][1]);*/
	return 0;
}