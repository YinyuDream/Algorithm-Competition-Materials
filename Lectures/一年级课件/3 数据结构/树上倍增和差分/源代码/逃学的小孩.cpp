#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,now,now2;
long long max_len,ans;
struct node{
	int to,next;
	long long weight;
}edge[maxn];
int head[maxn];
long long dis1[maxn],dis2[maxn];
void add(int u,int v,long long w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].weight=w;
	head[u]=k;
}
void dfs(int x,int fa,long long len)
{
	dis1[x]=len; 
	if(len>max_len){
		now=x;max_len=len;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa)
		{
			dfs(v,x,len+edge[i].weight);
		}
	}
}
void dfs2(int x,int fa,long long len)
{
	dis2[x]=len;
	if(len>max_len){
		now2=x;max_len=len;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa){
			dfs2(v,x,len+edge[i].weight);
		}
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1,-1,0),max_len=0,dfs2(now,-1,0),dfs(now2,-1,0);
	for(int i=1;i<=n;i++)
		ans=max(ans,min(dis1[i],dis2[i])+max_len);
	printf("%lld",ans);
	return 0;
}
