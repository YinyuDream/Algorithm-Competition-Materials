#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
struct node
{
	int to,next,dis;
} edge[maxn<<1];
int head[maxn],k=0,n,pre[maxn],cir[maxn],cnt=0,dfn[maxn],dfs_num=0,clen[maxn];
long long ans=0,f[maxn],u1[maxn],u2[maxn],v1[maxn],v2[maxn],len[maxn];
bool visit[maxn],oncir[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].dis=w;
	head[u]=k;
}
void dfs(int x)
{
	dfn[x]=++dfs_num;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==pre[x]) continue;
		if(!dfn[edge[i].to])
		{
			pre[edge[i].to]=x;
			clen[edge[i].to]=edge[i].dis;
			dfs(edge[i].to);
		}
		else if(dfn[edge[i].to]>dfn[x])
		{
			int now=edge[i].to;
			while(now!=x)
			{
				oncir[now]=true;
				len[++cnt]=clen[now];
				cir[cnt]=now;
				now=pre[now];
			}
			oncir[x]=true;
			len[++cnt]=edge[i].dis;
			cir[cnt]=x;
		}
	}
}
void dp(int x,int fa)//分别统计环上每一个点的子树中的直径 
{
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa||oncir[edge[i].to]) continue;
		dp(edge[i].to,x);
		ans=max(ans,f[x]+f[edge[i].to]+edge[i].dis);
		f[x]=max(f[x],f[edge[i].to]+edge[i].dis);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("3242.in","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=1,a,b,c;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	dfs(1);
	for(int i=1;i<=cnt;i++) dp(cir[i],cir[i]);
	long long sum=0,maxx=0;
	for(int i=1;i<=cnt;i++)
	{
		sum+=len[i-1];
		u1[i]=max(u1[i-1],f[cir[i]]+sum);
		v1[i]=max(v1[i-1],f[cir[i]]+sum+maxx);
		maxx=max(maxx,f[cir[i]]-sum);
	}
	long long temp=len[cnt];sum=maxx=len[cnt]=0;
	for(int i=cnt;i;i--)
	{
		sum+=len[i];
		u2[i]=max(u2[i+1],f[cir[i]]+sum);
		v2[i]=max(v2[i+1],f[cir[i]]+sum+maxx);
		maxx=max(maxx,f[cir[i]]-sum);
	}
	long long minn=v1[cnt];
	for(int i=1;i<cnt;i++) minn=min(minn,max(max(v1[i],v2[i+1]),u1[i]+u2[i+1]+temp));
	ans=max(ans,minn);
	printf("%.1lf\n",(double)ans/2);
	return 0;
}
