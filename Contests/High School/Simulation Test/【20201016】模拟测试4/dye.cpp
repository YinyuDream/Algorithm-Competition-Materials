#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,k,cnt,ans;
int a[maxn],p[maxn][maxn];
int fa[maxn];
struct node{
	int u,v,w;
}e[maxn];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void add(int u,int v,int w)
{
	e[++k].u=u;
	e[k].v=v;
	e[k].w=w;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("dye.in","r",stdin);
	freopen("dye.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		fa[i]=i;
		add(0,i,a[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&p[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			add(i,j,p[i][j]);
	sort(e+1,e+k+1,cmp);
	for(int i=1;i<=k;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			cnt++;
			fa[fx]=fy;
			ans+=e[i].w;
		}
		if(cnt==n)break;
	}
	printf("%d",ans);
	return 0;
}
