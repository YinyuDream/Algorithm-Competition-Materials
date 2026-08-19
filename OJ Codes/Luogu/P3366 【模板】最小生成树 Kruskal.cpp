#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,m,u,v,w,ans,cnt;
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&w),edge[i].x=u,edge[i].y=v,edge[i].val=w;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx!=fy)fa[fx]=fy,cnt++,ans+=edge[i].val;
		if(cnt==n-1)break;
	}
	if(cnt<n-1)printf("orz");
	else printf("%d",ans);
	return 0;
}
