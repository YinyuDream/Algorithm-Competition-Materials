#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,p=1,k,mx;
int ans[maxn],size[maxn],fa[maxn];
struct node{
	int u,v,w;
}e[maxn];
struct query{
	int id,val;
}q[maxn];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
bool cmps(query a,query b)
{
	return a.val<b.val;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++)
		scanf("%d",&q[i].val),q[i].id=i;
	sort(q+1,q+k+1,cmps);
	for(int i=1;i<=k;i++)
	{
		while(p<=m&&e[p].w<=q[i].val){
			int fx=find(e[p].u),fy=find(e[p].v);
			if(fx!=fy){
				fa[fx]=fy;
				size[fy]+=size[fx]+e[p].w;
				size[fx]=0;
				mx=max(mx,size[fy]);
			}else{
				size[fx]+=e[p].w;
				mx=max(mx,size[fx]);
			}
			p++;
		}
		ans[q[i].id]=mx;
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
	return 0;
}

