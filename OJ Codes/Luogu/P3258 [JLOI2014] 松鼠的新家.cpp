#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn],fa[maxn][21],deep[maxn],cf[maxn];
bool book[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	book[u]=true;
	for(int i=1;(1<<i)<=deep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]==false)fa[v][0]=u,deep[v]=deep[u]+1,dfs(v);
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;(1<<i)<=t;i++)
		if((1<<i)&t)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void Dfs(int x)
{
	book[x]=true;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(book[v]==false)Dfs(v),cf[x]+=cf[v];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1);
	for(int i=2;i<=n;i++)
	{
		int t=lca(a[i-1],a[i]);
		cf[a[i-1]]++;
		cf[a[i]]++;
		cf[t]--;
		cf[fa[t][0]]--;
	}
	memset(book,0,sizeof book);
	Dfs(1);
	for(int i=2;i<=n;i++)
		cf[a[i]]--;
	for(int i=1;i<=n;i++)
		printf("%d\n",cf[i]);
	return 0;
}
