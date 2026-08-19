#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,k;
long long ans;
struct node{
	int to,next,wt;
}edge[maxn*2];
int head[maxn],size[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs(v,u);
			size[u]+=size[v];
			ans+=1ll*edge[i].wt*abs(2*size[v]-n);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1);
	printf("%lld",ans);
	return 0;
}
