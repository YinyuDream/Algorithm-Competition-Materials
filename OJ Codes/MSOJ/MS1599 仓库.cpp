#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,cnt,pt=1;
struct node{int u,v,w;}e[maxn];
struct query{int w,id;}q[maxn];
int fa[maxn],ans[maxn];
bool cmp(query a,query b){return a.w>b.w;}
bool cmps(node a,node b){return a.w>b.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	//freopen("warehouse.in","r",stdin);
	//freopen("warehouse.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&q[i].w);
		q[i].id=i;
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	cnt=n;
	sort(q+1,q+k+1,cmp);
	sort(e+1,e+m+1,cmps);
	for(int i=1;i<=k;i++)
	{
		while(e[pt].w>=q[i].w&&pt<=m){
			int fx=find(e[pt].u),fy=find(e[pt].v);
			if(fx!=fy){
				fa[fx]=fy;
				cnt--;
			}
			pt++;
		}
		ans[q[i].id]=cnt;
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
	return 0;
}