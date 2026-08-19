#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,k,dis,l,r,cnt1,cnt2,mid,pt,pt2;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],pre[maxn],net[maxn],book[maxn];
int dis1[maxn],dis2[maxn],_dis[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs1(int u,int f,int d)
{
	if(dis<d)dis=d,l=u;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
			dfs1(v,u,d+edge[i].wt);
	}
}
int dfs2(int u,int f,int d)
{
	if(dis<d)dis=d,r=u;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			pre[v]=u;
			_dis[v]=edge[i].wt;
			dfs2(v,u,d+edge[i].wt);
		}
	}
}
int dfs3(int u,int f)
{
	int mx=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f&&book[v]==0)
			mx=max(dfs3(v,u)+edge[i].wt,mx);
	}
	return mx;
}
signed main(){
	//freopen("diameter.in","r",stdin);
	//freopen("diameter.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs1(1,1,0);
	dis=0;
	dfs2(l,l,0);
	printf("%lld\n",dis);
	for(int i=r;i!=l;i=pre[i])
		net[pre[i]]=i,book[i]=1,dis1[pre[i]]=dis1[i]+_dis[i];
	book[l]=1;
	for(int i=net[l];i!=r;i=net[i])
		dis2[i]=dis2[pre[i]]+_dis[i];
	for(int i=net[l],tp=0;i!=r;i=net[i])
	{
		
		if(dfs3(i,i)==dis2[i])cnt1=0;
		else cnt1++;
		if(max(dis1[i],dis2[i])<max(dis1[net[i]],dis2[net[i]])){
			pt=i;break;
		}
	}
	for(int i=pre[r],tp=0;i!=l;i=pre[i])
	{
		if(dfs3(i,i)==dis1[i])cnt2=0;
		else cnt2++;
		if(max(dis1[i],dis2[i])<=max(dis1[pre[i]],dis2[pre[i]])){
			pt2=i;break;
		}
	}
	printf("%lld",cnt1+cnt2);
	return 0;
}