#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,q,t,w;
int a[maxn],fa[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],size[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		size[i]=a[i];
		fa[i]=i;
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int fx=find(u),fy=find(v);
		if(fx!=fy)fa[fx]=fy,size[fy]+=size[fx],size[fx]=0;
	}
	for(int i=1,u,v,w;i<=q;i++){
		scanf("%d%d%d",&u,&v,&w);
		int fx=find(u),fy=find(v);
		if(fx!=fy)
			add(fx,fy,w);
	}
	for(int i=1;i<=n;i++)
		if(size[i])
			add(0,i,size[i]);
	return 0;
}
