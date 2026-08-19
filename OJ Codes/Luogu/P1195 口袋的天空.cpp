#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,m,u,v,w,k,ans,cnt;
int fa[maxn];
struct node{
	int x,y,val;
}edge[maxn];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&w),edge[i].x=u,edge[i].y=v,edge[i].val=w;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx!=fy)fa[fx]=fy,cnt++,ans+=edge[i].val;
		if(cnt==n-k)break;
	}
	if(cnt<n-k)printf("No Answer");
	else printf("%d",ans);
	return 0;
}
