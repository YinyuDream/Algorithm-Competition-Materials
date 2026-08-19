#include<cstdio>
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,m,k,val,ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],a[maxn],cnt[maxn][2];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			size+=dfs(v,u);
			cnt[u]+=cnt[v];
			ans+=(n-size)
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int fx=find(u),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			add(u,v,val);
			add(v,u,val);
		}
		val=(val*2)%mod;
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
