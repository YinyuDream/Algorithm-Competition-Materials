#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000005;
struct node
{
	int to,next,dis;
} edge[maxn<<1];
int n,head[maxn],k=0,size[maxn];
long long ans=0;
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].dis=w;
	head[u]=k;
}
void dfs(int x,int fa)
{
	size[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		dfs(edge[i].to,x);
		size[x]+=size[edge[i].to];
		ans+=(long long)edge[i].dis*abs((n-size[edge[i].to])-size[edge[i].to]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b,c;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
