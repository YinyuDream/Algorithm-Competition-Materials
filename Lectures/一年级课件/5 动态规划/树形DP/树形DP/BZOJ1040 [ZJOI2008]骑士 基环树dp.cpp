//RE
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000005;
struct node
{
	int to,next;
} edge[maxn<<1];
int n,head[maxn],k=1,s,t,num;
long long f[maxn][2],a[maxn];
bool visit[maxn];
inline void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs_pre(int x,int fa)
{
	visit[x]=true;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa) continue;
		if(visit[edge[i].to])
		{
			s=x;t=edge[i].to;
			num=i;
			return;
		}
		dfs_pre(edge[i].to,x);
	}
}
void dfs(int x,int fa)
{
	//f[][0]:ัก,f[][1]:ฒปัก 
	f[x][0]=a[x];f[x][1]=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to==fa||i==num||(i^1)==num) continue;
		dfs(edge[i].to,x);
		f[x][0]+=f[edge[i].to][1];
		f[x][1]+=max(f[edge[i].to][0],f[edge[i].to][1]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%lld%d",&a[i],&x),add(x,i),add(i,x);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]) continue;
		dfs_pre(i,i);
		dfs(s,s);
		long long temp=f[s][1];
		dfs(t,t);
		ans+=max(temp,f[t][1]);
	}
	printf("%lld\n",ans);
	return 0;
}
