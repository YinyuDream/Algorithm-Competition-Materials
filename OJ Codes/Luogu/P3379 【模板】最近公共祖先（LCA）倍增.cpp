#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,s,k;
int head[maxn],fa[maxn][20],deep[maxn];
bool book[maxn];
struct node{
	int to,next;
}edge[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int x)
{
	book[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		if(!book[edge[i].to])
		{
			fa[edge[i].to][0]=x;
			deep[edge[i].to]=deep[x]+1;
			dfs(edge[i].to);
		}
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;(1<<i)<=h;i++)
		if((1<<i)&h)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
	int u,v;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	fa[s][0]=s;
	dfs(s);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
