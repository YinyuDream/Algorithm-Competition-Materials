#include<cstdio>
using namespace std;
const int maxn=500000+10;

int n,m,s;
int fa[maxn][20],book[maxn],deep[maxn];
int ans[maxn];

int head[maxn];

struct node
{
	int to,next;
}e[maxn];

int k=0;
void adde(int u,int v)
{
	e[++k].to=v;
	e[k].next=head[u];
	head[u]=k;
}

void dfs(int u)
{
	book[u]=1;
	
	for(int i=1;(1<<i)<=deep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i>0;i=e[i].next)
	{
		if(book[e[i].to]==0)
		{
			fa[e[i].to][0]=u;
			deep[e[i].to]=deep[u]+1;
			dfs(e[i].to);
		}
	}
}
void swap(int &a,int &b)
{
	int temp=a;a=b;b=temp;
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;(1<<i)&h;i++)
	{
		x=fa[x][i];
	}
	if(x==y)return y;
	for(int i=19;i>=0;i--)
	{
		//if(fa[x][i]==fa[y][i])continue;
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	fa[s][0]=s;
	dfs(s);
	for(int i=1;i<=m;i++)
	{
		lca(u,v);
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
