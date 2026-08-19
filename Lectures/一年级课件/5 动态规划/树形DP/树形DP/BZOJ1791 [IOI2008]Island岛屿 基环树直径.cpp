//Ã»¹ýÑùÀý 
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1000005;
struct node
{
	int to,next,dis;
} edge[maxn<<1];
int head[maxn],n,rk[maxn],k=1,f[maxn],color_num=0,degree[maxn],q[maxn],color[maxn],dist[maxn],a[maxn],b[maxn];
bool visit[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].dis=w;
	head[u]=k;
}
void toposort()
{
	queue<int> q;
	for(int i=1;i<=n;i++) if(degree[i]==1) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			if(degree[edge[i].to]<=1) continue;
			dist[color[edge[i].to]]=max(dist[color[edge[i].to]],f[x]+f[edge[i].to]+edge[i].dis);
			f[edge[i].to]=max(f[edge[i].to],f[x]+edge[i].dis);
			if((--degree[edge[i].to])==1) q.push(edge[i].to);
		}
	}
}
void dfs(int x,int c)
{
	color[x]=c;visit[x]=true;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(visit[edge[i].to]) continue;
		dfs(edge[i].to,c);
	}
}
void dp(int x,int c)
{
	int cnt=0,i,now=x;
	do
	{
		a[++cnt]=f[now];degree[now]=1;
		for(int i=head[now];i;i=edge[i].next)
		{
			if(degree[edge[i].to]>1)
			{
				now=edge[i].to;
				b[cnt+1]=b[cnt]+edge[i].dis;
				break;
			}
		}
	} while(i);
	if(cnt==2)
	{
		int temp=0;
		for(int i=head[now];i;i=edge[i].next)
			if(edge[i].to==x)
				temp=max(temp,edge[i].dis);
		dist[c]=max(dist[c],f[x]+f[now]+temp);
		return;
	}
	for(int i=head[now];i;i=edge[i].next)
	{
		if(x==edge[i].to)
		{
			b[cnt+1]=b[cnt]+edge[i].dis;
			break;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		a[cnt+i]=a[i];
		b[cnt+i]=b[cnt+1]+b[i];
	}
	int head=1,tail=0;
	q[++tail]=1;
	for(int i=2;i<(cnt<<1);i++)
	{
		while(head<=tail&&i-q[head]>=cnt) head++;
		dist[c]=max(dist[c],a[i]+a[q[head]]+b[i]-b[q[head]]);
		while(head<=tail&&a[q[tail]]+b[i]-b[q[tail]]<=a[i]) tail--;
		q[++tail]=i;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,l;i<=n;i++)
	{
		scanf("%d%d",&x,&l);
		add(i,x,l);add(x,i,l);
		degree[i]++;degree[x]++;
	}
	for(int i=1;i<=n;i++) if(!rk[i]) dfs(i,++color_num);
	toposort();
	long long ans=0;
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++)
	{
		if(degree[i]>1&&!visit[color[i]])
		{
			visit[color[i]]=true;
			dp(i,color[i]);
			ans+=dist[color[i]];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
