#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e3+10;
int n,k,ans,cnt;
int a[maxn],c[maxn],fa[maxn];
struct node{
	int u,v,w;
}e[maxn*maxn];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("gokami.in","r",stdin);
	freopen("gokami.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			e[++k]=(node){i,j,c[i]+c[j]-a[i]*a[j]};
	sort(e+1,e+k+1,cmp);
	for(int i=1;i<=k;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	printf("%d",ans);
	return 0;
}
