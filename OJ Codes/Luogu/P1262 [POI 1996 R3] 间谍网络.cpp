#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=1e5+10; 
int n,p,k,r,t,id,a;
int buy[maxn],head[maxn],dfn[maxn],low[maxn],co[maxn],minx[maxn],cnt[maxn],sum[maxn];
struct node{
	int to,next;
}edge[maxn];
stack<int>st;
void add(int u,int v,int x)
{
	edge[x].to=v,edge[x].next=head[u],head[u]=x;
}
void dfs(int x)
{
	co[x]=1,a++;
	for(int i=head[x];i;i=edge[i].next)
		if(co[edge[i].to]==0)dfs(edge[i].to);
}
void tarjan(int x)
{
	low[x]=dfn[x]=++t;
	st.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dfn[v]==0)
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(co[v]==0)
		{
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x])
	{
		co[x]=++id;
		while(st.top()!=x)
		{
			minx[id]=min(minx[id],buy[st.top()]);
			co[st.top()]=id,st.pop();
		}
		minx[id]=min(minx[id],buy[st.top()]);
		st.pop();
	}
}
int main()
{
	memset(buy,0x3f,sizeof(buy));
	memset(minx,0x3f,sizeof(minx));
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++)
		scanf("%d%d",&k,&r),buy[k]=r;
	scanf("%d",&p);
	for(int i=1;i<=p;i++)
		scanf("%d%d",&k,&r),add(k,r,i);
	for(int i=1;i<=n;i++)
		if(buy[i]!=0x3f3f3f3f)dfs(i);
	if(a<n)
		for(int i=1;i<=n;i++)
			if(co[i]==0)
			{
				printf("NO\n%d",i);
				return 0;
			}
	memset(co,0,sizeof(co));
	for(int i=1;i<=n;i++)
		if(dfn[i]==0)
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=edge[j].next)
			if(co[i]!=co[edge[j].to])cnt[co[edge[j].to]]++;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(cnt[co[i]]==0&&sum[co[i]]==0)ans+=minx[co[i]],sum[co[i]]++;
	printf("YES\n%d",ans);	
	return 0;
}