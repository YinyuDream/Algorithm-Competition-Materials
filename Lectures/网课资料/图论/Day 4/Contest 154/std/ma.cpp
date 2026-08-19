#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

#define wmt 1,(n<<1),1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=100010;

int n,m,en,f[maxn][20],depth[maxn],q[maxn],l[maxn],r[maxn],y[maxn<<1],z[maxn],size[maxn],x[maxn<<3];

struct edge
{
	int e;
	edge *next;
}*v[maxn],ed[maxn<<1];

void add_edge(int s,int e)
{
	en++;
	ed[en].next=v[s];v[s]=ed+en;v[s]->e=e;
}

void update(int rt)
{
	x[rt]=x[rt<<1]+x[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if (l==r)
	{
		if (y[l]>0) x[rt]=z[y[l]];
		else x[rt]=-z[-y[l]];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}

void modify(int l,int r,int rt,int p,int v)
{
	if (l==r)
	{
		x[rt]+=v;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m) modify(lson,p,v);
	else modify(rson,p,v);
	update(rt);
}

long long query(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return x[rt];
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query(lson,nowl,nowr)+query(rson,nowl,nowr);
		else return query(lson,nowl,nowr);
	}
	else return query(rson,nowl,nowr);
}

int get_lca(int p1,int p2)
{
	if (depth[p1]<depth[p2]) swap(p1,p2);
	for (int x=18;x>=0;x--)
		if (depth[f[p1][x]] >= depth[p2]) p1=f[p1][x];
	if (p1==p2) return p1;
	for (int x=18;x>=0;x--)
		if (f[p1][x]!=f[p2][x]) p1=f[p1][x],p2=f[p2][x];
	return f[p1][0];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a=1;a<=n;a++)
		scanf("%d",&z[a]);
	for (int a=1;a<n;a++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		add_edge(s,e);
		add_edge(e,s);
	}
	int front=1,tail=1;
	q[1]=1;
	depth[1]=1;
	for (;front<=tail;)
	{
		int now=q[front++];
		for (edge *e=v[now];e;e=e->next)
			if (!depth[e->e])
			{
				f[e->e][0]=now;
				for (int x=1;x<=18;x++)
					f[e->e][x] = f[f[e->e][x-1]][x-1];
				depth[e->e]=depth[now]+1;
				q[++tail]=e->e;
			}
	}
	for (int a=n;a>=1;a--)
	{
		int now=q[a];
		size[now]++;
		size[f[now][0]]+=size[now];
	}
	l[1]=1;r[1]=n<<1;
	for (int a=1;a<=n;a++)
	{
		int now=q[a],x=l[now]+1;
		for (edge *e=v[now];e;e=e->next)
			if (depth[e->e] == depth[now]+1)
			{
				l[e->e]=x;
				r[e->e]=l[e->e]+(size[e->e]<<1)-1;
				x=r[e->e]+1;
			}
	}
	for (int a=1;a<=n;a++)
	{
		y[l[a]]=a;
		y[r[a]]=-a;
	}
	build(wmt);
	for (int a=1;a<=m;a++)
	{
		int opt;
		scanf("%d",&opt);
		if (opt==1)
		{
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			int lca=get_lca(p1,p2);
			long long v1=query(wmt,l[lca],l[p1]);
			long long v2=query(wmt,l[lca],l[p2]);
			long long v3=query(wmt,l[lca],l[lca]);
			printf("%lld\n",v1+v2-v3);
		}
		else if (opt==2)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			modify(wmt,l[p],v);
			modify(wmt,r[p],-v);
		}
		else if (opt==3)
		{
			int p;
			scanf("%d",&p);
		}
	}

	return 0;
}
