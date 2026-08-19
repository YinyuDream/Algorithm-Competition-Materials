#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n,k,top1,top2,t;
int head[maxn],a[maxn],deep[maxn],fa[maxn],ans[maxn],cnt[maxn],sonsize[maxn],tp[maxn];
struct node{
	int to,next;
}e[maxn];
void add(int x,int y)
{
	e[++k].to=y;
	e[k].next=head[x];
	head[x]=k;
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	while(deep[x]!=deep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
void dfs(int u,int f)
{
	int r=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v!=f)
		{
			r=1;
			deep[v]=deep[u]+1;
			fa[v]=u;
			sonsize[u]++;
			dfs(v,u);
		}
	}
	if(r==0)k++;
}
void pt(int x,int y,int z)
{
	memset(tp,0,sizeof(tp)),top2=0;
	if(z==0)
	{
		while(x!=y)
		{
			tp[++top2]=x;
			x=fa[x];
		}
		tp[++top2]=x;
		for(int i=1;i<=top2;i++)if(ans[top1]!=tp[i])ans[++top1]=tp[i];
	}
	else if(z==1)
	{
		swap(x,y);
		while(x!=y)
		{
			tp[++top2]=x;
			x=fa[x];
			cnt[x]++;
		}
		tp[++top2]=x;
		for(int i=top2;i>=1;i--)if(ans[top1]!=tp[i])ans[++top1]=tp[i];
	}
	else;
}
int main()
{
	freopen("climb.in","r",stdin);
	freopen("climb.out","w",stdout);
	scanf("%d",&n);
	int p,q;
	fa[1]=1;
	for(int i=1;i<n;i++)scanf("%d%d",&p,&q),add(p,q),add(q,p);
	k=0;
	dfs(1,1);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	a[0]=a[1];
	while(a[0]!=1)
	{
		tp[++top2]=a[0];
		a[0]=fa[a[0]];
		cnt[a[0]]++;
	}
	tp[++top2]=1;
	for(int i=top2;i>=1;i--)ans[++top1]=tp[i];
	memset(tp,0,sizeof(tp)),top2=0;
	for(int i=1;i<k;i++)
	{
		t=lca(a[i],a[i+1]);
		pt(a[i],t,0);
		pt(t,a[i+1],1);
	}
	a[0]=a[k];
	memset(tp,0,sizeof(tp)),top2=0;
	while(a[0]!=1)
	{
		tp[++top2]=a[0];
		a[0]=fa[a[0]];
	}
	tp[++top2]=1;
	for(int i=1;i<=top2;i++)if(ans[top1]!=tp[i])ans[++top1]=tp[i];
	for(int i=1;i<=n;i++)if((double)cnt[i]/sonsize[i]>1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=top1;i++)printf("%d ",ans[i]);
	return 0;
}
