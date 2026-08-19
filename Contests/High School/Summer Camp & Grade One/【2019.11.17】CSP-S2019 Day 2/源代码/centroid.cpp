#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int fa;
struct node{
	int from,to,next;
}edge[maxn];
int head[maxn],vi[maxn];
int k;
void add(int u,int v)
{
	edge[++k].to=v,edge[k].from=u,edge[k].next=head[u],head[u]=k;
}
bool book[maxn];
int dfs(int x,int b)
{
	book[x]=1;
	int k=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(book[i]==0&&vi[edge[i].to]==0)
		{
			vi[edge[i].to]=1;
			k+=dfs(edge[i].to,b);
			if(k>b/2);
		}
	}
}
int dfs2(int x)
{
	book[x]=1;
	int k=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(book[i]==0&&vi[edge[i].to]==0)
		{
			vi[edge[i].to]=1;
			k+=dfs2(edge[i].to);
			return k;
		}
	}
}
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		int n,u,v;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
			scanf("%d&d",&u,&v),add(u,v),add(v,u);
		for(int i=1;i<n;i++)
			book[i]=1,ans+=dfs(edge[i].from,dfs2(edge[i].from))+dfs(edge[i].to,dfs2(edge[i].to)),book[i]=0;
		printf("%d",ans);	
	}
	return 0;
}
