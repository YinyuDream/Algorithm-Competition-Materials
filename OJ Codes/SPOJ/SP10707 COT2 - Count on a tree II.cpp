#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,t,l,r,block,Ans;
int a[maxn],first[maxn],last[maxn],head[maxn],ans[maxn],book[maxn],num[maxn],sum[maxn];
int top[maxn],son[maxn],fa[maxn],deep[maxn],size[maxn];
struct node{
	int to,next;
}edge[maxn];
struct Query{
	int l,r,id,Lca;
}q[maxn];
bool cmp(Query a,Query b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	else
	return a.l/block<b.l/block;
}
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void lsh()
{
	int *b=new int[n];
	for(int i=1;i<=n;i++)
	b[i]=a[i];
	sort(b+1,b+n+1);
	int cnt=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	delete []b;
}
void dfs1(int u,int f)
{
	first[u]=++t;
	num[t]=u;
	size[u]=1;
	fa[u]=f;
	deep[u]=deep[f]+1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f){
			dfs1(v,u);
			size[u]+=size[v];
			if(size[son[u]]<size[v])
			son[u]=v;
		}
	}
	last[u]=++t;
	num[t]=u;
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	if(son[u])
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=fa[u]&&v!=son[u])
		dfs2(v,v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		u=fa[top[u]];
	}
	return deep[u]<deep[v]?u:v;
}
void update(int x)
{
	if(book[x]==0){
		sum[a[x]]++;
		if(sum[a[x]]==1)
		Ans++;
	}else{
		sum[a[x]]--;
		if(sum[a[x]]==0)
		Ans--;
	}
	book[x]^=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	lsh();
	for(int i=1;i<=n;i++);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(first[u]>first[v])
		swap(u,v);
		q[i].id=i;
		q[i].Lca=lca(u,v);
		if(q[i].Lca==u)
		{
			q[i].l=first[u];
			q[i].r=first[v];
			q[i].Lca=0;
		}
		else
		{
			q[i].l=last[u];
			q[i].r=first[v];
		}
	}
	block=sqrt(2*n);
	sort(q+1,q+m+1,cmp);
	
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)update(num[l++]);
		while(l>q[i].l)update(num[--l]);
		while(r<q[i].r)update(num[++r]);
		while(r>q[i].r)update(num[r--]);
		if(q[i].Lca)update(q[i].Lca);
		ans[q[i].id]=Ans;
		if(q[i].Lca)update(q[i].Lca);
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",ans[i]-1);
	return 0;
}