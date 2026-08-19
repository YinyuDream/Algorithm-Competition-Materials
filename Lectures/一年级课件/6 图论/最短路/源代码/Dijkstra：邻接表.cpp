#include<cstdio>
#include<cstring>
using namespace std;



const int maxn=100000+10;
int book[maxn],dis[maxn];

int head[maxn];
struct node
{
	int to,next,w;
}edge[maxn*2];

int k=0;
void adde(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].w=w;
	edge[k].next=head[u];
	head[u]=k;
}
int n,m,s;
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;book[s]=1;
	u=s;

	for(int i=1;i<=n-1;i++)
	{
		for(int j=head[u];j>0;j=edge[j].next)
		{
			v=edge[j].to;w=edge[j].w;
			if(book[v]==0 && dis[v]>dis[u]+w)dis[v]=dis[u]+w;
		}
		int minn=0;
		for(int j=1;j<=n;j++)
		{
			if(book[j]==0 && dis[minn]>dis[j])minn=j;
		}
		book[minn]=1;
		u=minn;
	}
	
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
}
