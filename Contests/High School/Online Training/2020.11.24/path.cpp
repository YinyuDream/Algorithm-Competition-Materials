#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
long long mx;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		mx+=w;
	}
	printf("%lld\n",mx%998244353);
	return 0;
}
