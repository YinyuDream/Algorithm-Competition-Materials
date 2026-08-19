#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
const int INF=0x7f7f7f7f7f7f7f7fll;
int n,m,k,cnt;
int ans,min_ans=0x7f7f7f7f7f7f7f7fll;
struct Edge{
	int u,v;
	int w;
	bool flag;
}a[maxn];
struct node{
	int to,next;
	int wt;
}edge[maxn];
int head[maxn];
int fa[maxn][20],_fa[maxn],deep[maxn];
int dp[maxn][20],dp2[maxn][20];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
bool change(Edge a,Edge b)
{
	return a.flag<b.flag;
}
int find(int x)
{
	return x==_fa[x]?x:_fa[x]=find(_fa[x]);
}
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].wt=w;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u,int f)
{
	for(int i=1;(1<<i)<=deep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		dp[u][i]=max(dp[u][i-1],dp[fa[u][i-1]][i-1]);
		dp2[u][i]=max(dp2[u][i-1],dp2[fa[u][i-1]][i-1]);
		int t=min(dp[u][i-1],dp[fa[u][i-1]][i-1]);
		if(dp[u][i-1]!=dp[fa[u][i-1]][i-1])
		dp2[u][i]=max(dp2[u][i],t);
	}
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			fa[v][0]=u;
			deep[v]=deep[u]+1;
			dp[v][0]=edge[i].wt;
			dp2[v][0]=-INF;
			dfs(v,u);
		}
	}
}
int lca(int u,int v)
{
	if(deep[u]<deep[v])
	swap(u,v);
	int t=deep[u]-deep[v];
	for(int i=0;i<=19;i++)
		if(t&(1<<i))
			u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int find_max(int u,int v)
{
	int t=deep[u]-deep[v];
	int ans=0;
	for(int i=0;i<=19;i++)
		if(t&(1<<i))
			ans=max(ans,dp[u][i]),
			u=fa[u][i];
	return ans;
}
int find_lmax(int u,int t,int v)
{
	int tp=deep[u]-deep[t];
	int ans=-INF,last=-INF;
	for(int i=0;i<=19;i++)
		if(tp&(1<<i))
		{
			ans=max(ans,dp2[u][i]);
			int tpf=min(last,dp[u][i]);
			if(last!=dp[u][i])
			ans=max(ans,tpf);
			last=max(last,dp[u][i]);
			u=fa[u][i];
		}
	tp=deep[v]-deep[t];
	int ans2=-INF,last2=-INF;
	for(int i=0;i<=19;i++)
		if(tp&(1<<i))
		{
			ans2=max(ans2,dp2[v][i]);
			int tpf=min(last2,dp[v][i]);
			if(last2!=dp[v][i])
			ans2=max(ans2,tpf);
			last2=max(last2,dp[v][i]);
			v=fa[v][i];
		}
	ans=max(ans,ans2);
	int max_e=min(last,last2);
	if(last!=last2)
	ans=max(ans,max_e);
	return ans;
}
int query(int u,int v,int w)
{
	int t=lca(u,v);
	int max_edge=max(find_max(u,t),find_max(v,t));
	int lmax_edge=find_lmax(u,t,v);
	if(max_edge!=w)
		return w-max_edge;
	else
		return w-lmax_edge;
}
main(){
	int s=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		if(u!=v)
		a[++s].u=u,
		a[s].v=v,
		a[s].w=w;
	}
	m=s;	
	for(int i=1;i<=n;i++)
		_fa[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy)
		{
			_fa[fx]=fy;
			add(a[i].u,a[i].v,a[i].w);
			add(a[i].v,a[i].u,a[i].w);
			a[i].flag=1;
			ans+=a[i].w;
		}
	}
	dfs(1,1);
	sort(a+1,a+m+1,change);
	while(a[cnt+1].flag==0)cnt++;
	for(int i=1;i<=cnt;i++)
	{
		int u=a[i].u,v=a[i].v;
		int w=a[i].w;
		min_ans=min(min_ans,query(u,v,w));
	}
	printf("%lld",ans+min_ans);
	return 0;
}
