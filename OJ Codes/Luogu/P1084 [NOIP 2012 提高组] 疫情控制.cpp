#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,k,l,r,ans,cnt,top;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],c[maxn],_dis[maxn],is[maxn],deep[maxn],fa[maxn][20],dis[maxn][20];
void add(int u,int v,int w)
{
	edge[++k]={v,head[u],w};
	head[u]=k;
}
void pre_dfs(int u,int f)
{
	for(int i=1;(1<<i)<=deep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1],
		dis[u][i]=dis[u][i-1]+dis[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			is[u]=1;
			dis[v][0]=edge[i].wt;
			_dis[v]=_dis[u]+edge[i].wt;
			deep[v]=deep[u]+1;
			fa[v][0]=u;
			pre_dfs(v,u);
		}
	}
}
int a[maxn],b[maxn],book[maxn];
bool dfs(int u,int f)
{
	if(!is[u])return false;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f&&book[v]==0)
			if(!dfs(v,u))return false;
	}
	return true;
}
void query(int u,int d)
{
	if(d-_dis[u]>=0){
		for(int i=20;i>=0;i--)
		if(fa[u][i]&&fa[u][i]!=1)
			u=fa[u][i];
		a[++cnt]=dis[u][0];
		return ;
	}
	for(int i=20;i>=0;i--)
		if(fa[u][i]&&d-dis[u][i]>=0)
			d-=dis[u][i],u=fa[u][i];
	book[u]=1;
}
bool check(int x)
{
	cnt=top=0;
	memset(book,0,sizeof book);
	for(int i=1;i<=m;i++)//询问各个军队在x时间内可以到达的最浅深度
		query(c[i],x);
	for(int i=head[1];i;i=edge[i].next)//询问还有多少1的子树没有被覆盖
		if(dfs(edge[i].to,1))
			b[++top]=edge[i].wt;

}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w);
		add(u,v,w);
		r+=w;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	pre_dfs(1,1);
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
