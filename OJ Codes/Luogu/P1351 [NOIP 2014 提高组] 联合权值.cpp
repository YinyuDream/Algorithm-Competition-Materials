#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,mod=10007;
int n,ans,k,w[maxn];
long long sum;
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
void dfs(int u,int f)
{
	int _max=0,_lmax=0;
	long long size=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			dfs(v,u);
			if(_max<w[v])_lmax=_max,_max=w[v];
			else if(_max>=w[v]&&(!_lmax||w[v]>_lmax))_lmax=w[v];
			sum+=1ll*w[v]*size;
			size+=w[v];
		}
	}
	if(_max<w[f])_lmax=_max,_max=w[f];
	else if(_max>=w[f]&&(!_lmax||w[f]>_lmax))_lmax=w[f];
	ans=max(ans,_lmax*_max);
	sum+=1ll*size*w[f];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs(1,0);
	printf("%d %lld\n",ans,(sum*2)%mod);
	return 0;
}
