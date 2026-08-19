#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=510;
int n,m,k,f,ans=0x3f3f3f3f;
int fa[2*maxn],big[2*maxn],mapp[maxn][maxn];
struct node{
	int u,v;
}edge[maxn*maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&f);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&edge[i].u,&edge[i].v);
	for(int i=1;i<=f;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		fa[find(a)]=find(b);
	}
	for(int i=1;i<=m;i++)
	{
		if(!mapp[find(edge[i].u)][edge[i].v])
		{
			big[find(edge[i].u)]++;
			mapp[find(edge[i].u)][edge[i].v]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(big[i])ans=min(ans,big[i]);
	ans=min(n,ans+k);
	printf("%d",ans);
	return 0;
}
