#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T,n,k,cnt_edge;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
int f[maxn][2];
void add(int u,int v)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	head[u]=cnt_edge;
}
void dfs(int u,int fa)
{
	int mx=0;
	f[u][1]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa){
			dfs(v,u);
			f[u][1]+=f[v][0];
			f[u][0]+=f[v][0];
			mx=max(mx,f[v][1]-f[v][0]);
		}
	}
	f[u][0]+=mx;
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(edge,0,sizeof edge);
		memset(head,0,sizeof head);
		memset(f,0,sizeof f);
		cnt_edge=0;
		scanf("%d%d",&n,&k);
		for(int i=2,v;i<=n;i++)
			scanf("%d",&v),add(v,i),add(i,v);
		dfs(1,1);
		if(k<=f[1][0]*2)printf("%d\n",k/2+(k&1));
		else printf("%d\n",k-f[1][0]);
	}
	return 0;
}