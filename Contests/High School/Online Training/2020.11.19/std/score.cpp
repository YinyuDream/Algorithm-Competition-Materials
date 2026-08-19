#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f,lim=18;

struct edge
{
	int v,nxt;
}e[maxn<<1];
struct Line
{
	int l,r,h,w;
	Line(int l,int r,int h,int w) : l(l),r(r),h(h),w(w) {}
	Line() {}
	bool operator < (const Line &x) const {
		return h<x.h;
	}
}li[maxn*20];
int head[maxn],kt,n,m,tot;
int dfn[maxn],dcnt,siz[maxn],dep[maxn],fa[maxn][lim+1],sum[maxn];

class SegmentTree
{
private:
	int wife[maxn<<2],tag[maxn<<2];
	inline void update(int u,int val) {wife[u]+=val;tag[u]+=val;}
	inline void pushdown(int u)
	{
		if(!tag[u]) return;
		update(u<<1,tag[u]);update(u<<1|1,tag[u]);
		tag[u]=0;
	}
public:
	void modify(int u,int l,int r,int x,int y,int val)
	{
		if(x<=l&&r<=y) return update(u,val);
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid) modify(u<<1,l,mid,x,y,val);
		if(y>mid) modify(u<<1|1,mid+1,r,x,y,val);
		wife[u]=max(wife[u<<1],wife[u<<1|1]);
	}
	int query() {return wife[1];}
}wife;

template<typename T>
inline void read(T &x)
{
    int f=1;char c;
    while(!isdigit(c=getchar())) if(c=='-') f=-1;
    x=c^48;
    while(isdigit(c=getchar())) x=x*10+(c^48);
    x*=f;
}

inline void addedge(int u,int v) {e[++kt]=(edge){v,head[u]};head[u]=kt;}

void dfs(int u,int f)
{
	dfn[u]=++dcnt;siz[u]=1;dep[u]=dep[f]+1;fa[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].v!=f) dfs(e[i].v,u),siz[u]+=siz[e[i].v];
}

inline int getson(int u,int v)
{
	for(int i=lim;~i;--i)
		if(fa[u][i]&&dep[fa[u][i]]>dep[v]) u=fa[u][i];
	return u;
}

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	read(n);read(m);
	for(int i=1,u,v;i<n;++i)
		read(u),read(v),addedge(u,v),addedge(v,u);
	dfs(1,0);
	for(int i=1,u,v,w;i<=m;++i)
	{
		read(u);read(v);read(w);
		int l1=dfn[u],r1=dfn[u]+siz[u]-1,l2=dfn[v],r2=dfn[v]+siz[v]-1;
		if(u==v)
			sum[u]+=w;
		else if(l1<=l2&&r2<=r1)
		{
			u=getson(v,u);l1=dfn[u];r1=dfn[u]+siz[u]-1;
			li[++tot]=Line(1,l1-1,l2,w),li[++tot]=Line(1,l1-1,r2+1,-w);
			li[++tot]=Line(r1+1,n,l2,w),li[++tot]=Line(r1+1,n,r2+1,-w);
		}
		else if(l2<=l1&&r1<=r2)
		{
			v=getson(u,v);l2=dfn[v];r2=dfn[v]+siz[v]-1;
			li[++tot]=Line(l1,r1,1,w),li[++tot]=Line(l1,r1,l2,-w);
			li[++tot]=Line(l1,r1,r2+1,w),li[++tot]=Line(l1,r1,n+1,-w);
		}
		else li[++tot]=Line(l1,r1,l2,w),li[++tot]=Line(l1,r1,r2+1,-w);
	}
	for(int u=1;u<=n;++u)
	{
		if(sum[u]==0) continue;
		int l1=dfn[u],r1=dfn[u]+siz[u]-1,l2,r2,w=sum[u];
		li[++tot]=Line(1,l1-1,l1,w);li[++tot]=Line(1,l1-1,r1+1,-w);
		li[++tot]=Line(r1+1,n,l1,w);li[++tot]=Line(r1+1,n,r1+1,-w);
		li[++tot]=Line(l1,r1,1,w);li[++tot]=Line(l1,r1,l1,-w);
		li[++tot]=Line(l1,r1,r1+1,w);li[++tot]=Line(l1,r1,n+1,-w);
		for(int i=head[u];i;i=e[i].nxt)
			if(e[i].v!=fa[u][0])
			{
				l2=dfn[e[i].v];r2=dfn[e[i].v]+siz[e[i].v]-1;
				if(l2!=l1) li[++tot]=Line(l1,l2-1,l2,w),li[++tot]=Line(l1,l2-1,r2+1,-w);
				if(r1!=r2) li[++tot]=Line(r2+1,r1,l2,w),li[++tot]=Line(r2+1,r1,r2+1,-w);
			}
	}
	sort(li+1,li+tot+1);
	int ans=-inf;
	for(int i=1,j=1;i<=n+1&&j<=tot;++i)
	{
		for(;li[j].h==i&&j<=tot;++j)
		{
			if(li[j].l>li[j].r) continue;
			wife.modify(1,1,n,li[j].l,li[j].r,li[j].w);
		}
		ans=max(ans,wife.query());
	}
	printf("%d\n",ans);
	return 0;
}
