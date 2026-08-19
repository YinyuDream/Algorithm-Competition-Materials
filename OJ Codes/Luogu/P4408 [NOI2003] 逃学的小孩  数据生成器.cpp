#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,k,now,max_len,now2,ans;
struct node{
	int to,next,weight;
}edge[maxn];
int head[maxn],dis1[maxn],dis2[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].weight=w;
	head[u]=k;
}
void dfs(int x,int fa,int len)
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
void dfs2(int x,int fa,int len)
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
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1,-1,0),max_len=0,dfs2(now,-1,0),dfs(now2,-1,0);
	//printf("%lld %lld\n",now,now2);
	//for(int i=1;i<=n;i++)
	//	printf("%d\n",dis2[i]);
	for(int i=1;i<=n;i++)
		ans=max(ans,min(dis1[i],dis2[i])+max_len);
	printf("%lld",ans);
	return 0;
}