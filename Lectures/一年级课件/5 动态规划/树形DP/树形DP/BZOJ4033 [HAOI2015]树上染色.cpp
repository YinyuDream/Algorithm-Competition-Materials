#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2005;
struct node
{
	int to,next,dis;
} edge[maxn<<1];
int size[maxn],n,m,head[maxn],k=0,mm;
long long f[maxn][maxn];
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
		for(int j=min(m,size[x]+size[edge[i].to]);~j;j--)
			for(int k=max(0,j-size[x]);k<=min(j,size[edge[i].to]);k++)
				f[x][j]=max(f[x][j],f[edge[i].to][k]+f[x][j-k]+(long long)edge[i].dis*(k*(m-k)+(size[edge[i].to]-k)*(mm-size[edge[i].to]+k)));
		size[x]+=size[edge[i].to];
	}
}
int main()
{
	scanf("%d%d",&n,&m);mm=n-m;
	for(int i=1,a,b,c;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	dfs(1,1);
	printf("%lld",f[1][m]);
	return 0;
}
