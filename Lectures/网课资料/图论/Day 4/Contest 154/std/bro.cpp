#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=510;
const int maxm=maxn*maxn*8+10000;
const int INF=0x3f3f3f3f;

int n,m,k,en,t,cnt,size,z[maxn<<3][2],dfn[maxn<<1],low[maxn<<1],s[maxn<<1],belong[maxn<<1];

bool instack[maxn<<1];

struct point
{
	int x,y;
	void init()
	{
		scanf("%d%d",&x,&y);
	}
}p[maxn];

int operator-(const point &a,const point &b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

struct edge
{
	int e;
	edge *next;
}*v[maxn<<1],ed[maxm];

void add_edge(int s,int e)
{
	en++;
	ed[en].next=v[s];v[s]=ed+en;v[s]->e=e;
}

void dfs(int now)
{
	t++;
	dfn[now]=low[now]=t;
	instack[now]=true;
	s[++size]=now;
	for (edge *e=v[now];e;e=e->next)
		if (!dfn[e->e])
		{
			dfs(e->e);
			low[now]=min(low[now],low[e->e]);
		}
		else
		{
			if (instack[e->e]) low[now]=min(low[now],dfn[e->e]);
		}
	if (low[now]==dfn[now])
	{
		cnt++;
		belong[now]=cnt;
		instack[now]=false;
		while (s[size]!=now)
		{
			belong[s[size]]=cnt;
			instack[s[size]]=false;
			size--;
		}
		size--;
	}
}

bool check(int vx)
{
	en=0;
	memset(v,0,sizeof(v));
	memset(dfn,0,sizeof(dfn));
	t=0;
	for (int a=1;a<=n;a++)
		for (int b=a+1;b<=n;b++)
		{
			if ((p[a]-p[0])+(p[b]-p[0])>vx)
			{
				add_edge(a,b+n);
				add_edge(b,a+n);
			}
			if ((p[a]-p[n+1])+(p[b]-p[n+1])>vx)
			{
				add_edge(a+n,b);
				add_edge(b+n,a);
			}
			if ((p[a]-p[0])+(p[b]-p[n+1])+(p[n+1]-p[0])>vx)
			{
				add_edge(a,b);
				add_edge(b+n,a+n);
			}
			if ((p[a]-p[n+1])+(p[b]-p[0])+(p[n+1]-p[0])>vx)
			{
				add_edge(b,a);
				add_edge(a+n,b+n);
			}
		}
	for (int a=1;a<=m;a++)
	{
		int p1=z[a][0],p2=z[a][1];
		add_edge(p1,p2+n);
		add_edge(p2,p1+n);
		add_edge(p1+n,p2);
		add_edge(p2+n,p1);
	}
	for (int a=m+1;a<=m+k;a++)
	{
		int p1=z[a][0],p2=z[a][1];
		add_edge(p1,p2);
		add_edge(p2,p1);
		add_edge(p1+n,p2+n);
		add_edge(p2+n,p1+n);
	}
	for (int a=1;a<=n+n;a++)
		if (!dfn[a]) dfs(a);
	for (int a=1;a<=n;a++)
		if (belong[a]==belong[a+n]) return false;
	return true;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	p[0].init();
	p[n+1].init();
	for (int a=1;a<=n;a++)
		p[a].init();
	for (int a=1;a<=m+k;a++)
		scanf("%d%d",&z[a][0],&z[a][1]);
	int l=0,r=INF;
	while (l+1!=r)
	{
		int m=(l+r)>>1;
		if (check(m)) r=m;
		else l=m;
	}
	if (r==INF) r=-1;
	printf("%d\n",r);

	return 0;
}

