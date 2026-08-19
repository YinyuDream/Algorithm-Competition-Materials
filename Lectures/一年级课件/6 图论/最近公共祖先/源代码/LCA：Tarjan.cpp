#include<cstdio>
using namespace std;
const int maxn=500000+10;

int n,m,s;
int fa[maxn],book[maxn];
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

int head2[maxn];
struct node2
{
	int to,next;
}e2[maxn];

int k2=0;
void add2(int u,int v)
{
	e2[++k2].to=v;
	e2[k2].next=head2[u];
	head2[u]=k2;
}

int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void tarjan(int u)
{
	book[u]=1;
	for(int i=head[u];i>0;i=e[i].next)
	{
		if(book[e[i].to]==0)
		{
			tarjan(e[i].to);
			fa[e[i].to]=u;
		}
	}
	for(int i=head2[u];i>0;i=e2[i].next)
	{
		if(book[e2[i].to]==1)
		{
			//printf("%dºÍ%dµÄlcaÊÇ%d\n",u,e2[i].to,find(e2[i].to));
			ans[(i+1)/2]=find(e2[i].to);
		}
	}
	return ;
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
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add2(u,v);add2(v,u);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	tarjan(s);
	for(int i=1;i<=m;i++)	printf("%d\n",ans[i]);
	return 0;
}
