#include<bits/stdc++.h>
using namespace std;
constexpr int MN=300005;
struct segt
{
	int lc,rc;
	long long val;
}T[20000005];
int n,m,U[MN],V[MN],cnt,rt[MN],fa[MN],siz[MN],hson[MN],dfn[MN],rnk[MN];
long long ans[MN],res;
vector<int>g[MN];
vector<pair<int,int>>v[MN];
map<int,int>mp;
void change(int&rt,int l,int r,int x,int y)
{
	T[++cnt]=T[rt],rt=cnt;
	T[rt].val+=y;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x>mid)
		change(T[rt].rc,mid+1,r,x,y);
	else
		change(T[rt].lc,l,mid,x,y);
}
long long ask(int rt,int l,int r,int x,int y)
{
	if(!rt)
		return 0;
	if(x<=l&&r<=y)
		return T[rt].val;
	int mid=(l+r)>>1;
	long long res=0;
	if(x<=mid)
		res=ask(T[rt].lc,l,mid,x,y);
	if(y>mid)
		res+=ask(T[rt].rc,mid+1,r,x,y);
	return res;
}
void dfs(int x,int f)
{
	siz[x]=1;
	fa[x]=f;
	rnk[dfn[x]=++cnt]=x;
	for(int y:g[x])
		if(y!=f)
		{
			dfs(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[hson[x]])
				hson[x]=y;
		}
}
inline void add(int x)
{
	auto r=mp.lower_bound(x),l=r;
	l--;
	if(x+1==r->first)
		if(x-1==l->second)
		{
			res+=ask(rt[x],1,n,x,x)-ask(rt[x-1],1,n,x,x);
			res-=ask(rt[r->second],1,n,l->first,x)-ask(rt[x-1],1,n,l->first,x);
			int tr=r->second;
			mp.erase(r);
			l->second=tr;
		}
		else
		{
			res+=ask(rt[x],1,n,l->second+1,x-1)-ask(rt[x-1],1,n,l->second+1,x-1);
			res-=ask(rt[r->second],1,n,x,x)-ask(rt[x],1,n,x,x);
			int tr=r->second;
			mp.erase(r);
			mp[x]=tr;
		}
	else if(x-1==l->second)
	{
		res+=ask(rt[r->first-1],1,n,x,x)-ask(rt[x],1,n,x,x);
		res-=ask(rt[x],1,n,l->first,x-1)-ask(rt[x-1],1,n,l->first,x-1);
		l->second=x;
	}
	else
	{
		res+=ask(rt[r->first-1],1,n,l->second+1,x)-ask(rt[x-1],1,n,l->second+1,x);
		res-=ask(rt[x],1,n,x,x)-ask(rt[x-1],1,n,x,x);
		mp[x]=x;
	}
}
void solve(int x)
{
	for(int y:g[x])
		if(y!=fa[x]&&y!=hson[x])
		{
			solve(y);
			res=0,mp.clear(),mp[1]=0,mp[n+1]=n;
		}
	if(hson[x])
		solve(hson[x]);
	if(x==1)
		return;
	add(x);
	for(int y:g[x])
		if(y!=fa[x]&&y!=hson[x])
			for(int j=dfn[y];j<dfn[y]+siz[y];j++)
				add(rnk[j]);
	ans[x]=res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		U[i]=x,V[i]=y;
	}
	while(m--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		v[r].emplace_back(l,x);
	}
	for(int i=1;i<=n;i++)
	{
		rt[i]=rt[i-1];
		for(auto e:v[i])
			change(rt[i],1,n,e.first,e.second);
	}
	cnt=0;
	dfs(1,0);
	mp[1]=0,mp[n+1]=n,solve(1);
	for(int i=1;i<n;i++)
		if(fa[U[i]]==V[i])
			printf("%lld\n",ans[U[i]]);
		else
			printf("%lld\n",ans[V[i]]);
	return 0;
}
