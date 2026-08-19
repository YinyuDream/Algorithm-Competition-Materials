#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,q,k,cnt,t1,t2,l=1,r,now,block;
int v[maxn],w[maxn],a[maxn];
long long num,ans[maxn];
struct node{
	int to,next;
}edge[maxn];
struct query{
	int l,r,lca,id,t;
}que[maxn];
struct Change{
	int pos,pos2,color;
}c[maxn];
int head[maxn];
int first[maxn],last[maxn],euler[maxn];//欧拉序 
int fa[maxn],son[maxn],top[maxn],size[maxn],deep[maxn];//树剖LCA 
int book[maxn],flag[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
bool cmp(query a,query b)
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
void dfs1(int u,int f)
{
	first[u]=++cnt;
	euler[cnt]=u;
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f)
		{
			deep[v]=deep[u]+1;
			dfs1(v,u);
			fa[v]=u;
			size[u]+=size[v];
			if(size[son[u]]<size[v])
			son[u]=v; 
		}
	}
	last[u]=++cnt;
	euler[cnt]=u;
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
void update(int pos)
{
	if(flag[pos]==0){
		book[a[pos]]++;
		num+=(long long)v[a[pos]]*w[book[a[pos]]];
	}else{
		book[a[pos]]--;
		num-=(long long)v[a[pos]]*w[book[a[pos]]+1];
	}
	flag[pos]^=1;
}
void change(int tme)
{
	if(flag[c[tme].pos]==1)
	{
		book[c[tme].color]++;
		num+=(long long)v[c[tme].color]*w[book[c[tme].color]];
		book[a[c[tme].pos]]--;
		num-=(long long)v[a[c[tme].pos]]*w[book[a[c[tme].pos]]+1];
	}
	swap(c[tme].color,a[c[tme].pos]);
}
signed main(){
	n=read();m=read();q=read();
	for(int i=1;i<=m;i++)
	v[i]=read();
	for(int i=1;i<=n;i++)
	w[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	a[i]=read();
	dfs1(1,1);
	dfs2(1,1);
	for(int i=1;i<=q;i++)
	{
		int opt=read(),x=read(),y=read();
		if(opt==0){
			t1++;
			c[t1].pos=x;
			c[t1].color=y;
		}else{
			t2++;
			que[t2].t=t1;
			que[t2].id=t2;
			que[t2].lca=lca(x,y);
			if(first[x]>first[y])
			swap(x,y);
			if(que[t2].lca==x){
				que[t2].l=first[x];
				que[t2].r=first[y];
				que[t2].lca=0;
			}else{
				que[t2].l=last[x];
				que[t2].r=first[y];
			}
		}
	}
	block=pow(n,2.0/3);
	sort(que+1,que+t2+1,cmp);
	for(int i=1;i<=t2;i++)
	{
		while(l<que[i].l)update(euler[l++]);
		while(l>que[i].l)update(euler[--l]);
		while(r<que[i].r)update(euler[++r]);
		while(r>que[i].r)update(euler[r--]);
		while(now<que[i].t)change(++now);
		while(now>que[i].t)change(now--);
		if(que[i].lca)update(que[i].lca);
		ans[que[i].id]=num;
		if(que[i].lca)update(que[i].lca);
	}
	for(int i=1;i<=t2;i++)
	printf("%lld\n",ans[i]);
	return 0;
}