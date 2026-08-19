#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,k,cut,ans=0x7f7f7f7f7f7f7f7fll;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],fa[maxn];
int w[maxn],son1[maxn],son2[maxn],size[maxn],a[maxn],deep[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	fa[u]=f;
	size[u]=w[u];
	a[u]=w[u]*deep[u];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			deep[v]=deep[u]+1;
			dfs(v,u);
			size[u]+=size[v];
			a[u]+=a[v];
			if(size[son1[u]]<=size[v]){
				son2[u]=son1[u];
				son1[u]=v;
			}else if(size[son2[u]]<=size[v]){
				son2[u]=v;
			}
		}
	}
}
void get_ans(int u,int sz,int num,int &cnt)
{
	cnt=min(cnt,num);
	int v=son1[u];
	if(size[son1[u]]<size[son2[u]]||v==cut)v=son2[u];
	if(v&&size[v]*2>size[u])get_ans(v,sz,num+sz-2*size[v],cnt);
}
void solve(int u)
{
	for(int j=head[u];j;j=edge[j].next)
	{
		int v=edge[j].to;
		if(v!=fa[u])
		{
			int _a=0x7f7f7f7f7f7f7f7fll,b=0x7f7f7f7f7f7f7f7fll;
			cut=v;
			for(int i=u;i;i=fa[i])
			size[i]-=size[v];
			get_ans(1,size[1],a[1]-a[v],_a);
			get_ans(v,size[v],a[v]-size[v]*deep[v],b);
			ans=min(ans,_a+b);
			for(int i=u;i;i=fa[i])
			size[i]+=size[v];
			solve(v);
		}
	}
}
main(){
	//freopen("center.in","r",stdin);
	//freopen("center.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	dfs(1,0);
	solve(1);
	printf("%lld",ans);
	return 0;
}