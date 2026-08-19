#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,k2,cnt,leaf,tot,sum;
struct node{
	int to,next;
}edge[maxn],edge2[maxn];
struct Edge{
	int u,v,w,id,flag;
}e[maxn];
int head[maxn],head2[maxn],l[maxn],r[maxn],c[maxn],ans[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int dfs(int u,int f)
{
	int size=1;l[u]=0x3fffffff;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			size+=dfs(v,u);
			l[u]=min(l[u],l[v]);
			r[u]=max(r[u],r[v]);
		}
	}
	if(size==1)
		l[u]=r[u]=++leaf;
	e[++cnt]={l[u],r[u]+1,c[u],u,0};
}
int fa[maxn];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			e[i].flag=1;
			ans[++tot]=e[i].id;
			sum+=e[i].w;
			fa[fx]=fy;
		}
	}
	printf("%d %d\n",sum,tot);
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)
	printf("%d ",ans[i]);
	return 0;
}
