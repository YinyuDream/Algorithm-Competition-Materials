#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,ans,cnt;
struct edge{
	int u,v,w;
}e[maxn];
int fa[maxn];
bool cmp(edge a,edge b)
{
	return a.w>b.w;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
		{
			cnt++;
			fa[fx]=fy;
			ans+=e[i].w;
		}
		else continue;
		if(cnt==k)
		break;
	}
	printf("%d",ans);
	return 0;
}
