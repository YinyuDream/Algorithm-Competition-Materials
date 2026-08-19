#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
struct node{
	int u,v;
}e[maxn];
int fa[maxn],mx[maxn];
long long ans;
bool cmp(node x,node y)
{
	return max(a[x.u],a[x.v])<max(a[y.u],a[y.v]);
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx[i]=a[i];
		fa[i]=i;
	}
	for(int i=1;i<n;i++)
		scanf("%d%d",&e[i].u,&e[i].v);
	sort(e+1,e+n,cmp);
	for(int i=1;i<n;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		ans+=mx[fx]+mx[fy];
		fa[fx]=fy;
		mx[fy]=max(mx[fy],mx[fx]);
	}
	printf("%lld",ans);
	return 0;
}
