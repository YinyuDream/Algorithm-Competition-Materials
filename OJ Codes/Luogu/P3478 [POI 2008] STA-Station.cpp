#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn],deep[maxn],size[maxn];
long long sum[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			deep[v]=deep[u]+1;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void dp(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			sum[v]=sum[u]+n-2*size[v];
			dp(v,u);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		sum[i]+=deep[i];
	dp(1,1);
	for(int i=1;i<=n;i++)
		if(!ans||sum[ans]<sum[i])
			ans=i;
	printf("%d",ans);
	return 0;
}
