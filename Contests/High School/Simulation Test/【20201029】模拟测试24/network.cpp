#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e3+10,p=998244353;
int T,n,k;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs(v,u);
		}
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(edge,0,sizeof edge);
		memset(head,0,sizeof head);
		k=0;
		scanf("%d",&n);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1,1);
	}
	return 0;
}
