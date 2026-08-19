#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,s,k,cnt;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
int val[maxn],deep[maxn],fa[maxn],top[maxn],size[maxn],son[maxn],tid[maxn],old[maxn],dis[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u,int f)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v]=u;
			deep[v]=deep[u]+1;
			val[v]=edge[i].wt;
			dis[v]=dis[u]+edge[i].wt;
			dfs(v,u);
			size[u]+=size[v];
			if(!son[u]||size[son[u]]<size[v])
			son[u]=v;
		}
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	tid[u]=++cnt;
	old[cnt]=u;
	if(!son[u])return ;
	dfs2(son[u],tp);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=son[u]&&v!=fa[u]){
			dfs2(v,v);
		}
	}
}
struct seg{
	int l,r,lmax,rmax,sum;
}tree[maxn];
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].sum=tree[id].lmax=tree[id].rmax=val[old[l]];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].lmax=max(tree[id*2].lmax,tree[id*2].sum+tree[id*2+1].lmax);
	tree[id].rmax=max(tree[id*2+1].rmax,tree[id*2+1].sum+tree[id*2].rmax);
}
seg query_lmax(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id];
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query_lmax(id*2,l,r);
	else if(l>mid)return query_lmax(id*2+1,l,r);
	else{
		seg t1=query_lmax(id*2,l,mid),t2=query_lmax(id*2+1,mid+1,r),t3;
		t3.sum=t1.sum+t2.sum;
		t3.lmax=max(t1.lmax,t1.sum+t2.lmax);
		return t3;
	}
}
seg query_rmax(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id];
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query_lmax(id*2,l,r);
	else if(l>mid)return query_lmax(id*2+1,l,r);
	else{
		seg t1=query_rmax(id*2,l,mid),t2=query_rmax(id*2+1,mid+1,r),t3;
		t3.sum=t1.sum+t2.sum;
		t3.rmax=max(t2.rmax,t2.sum+t1.rmax);
		return t3;
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v]){
		if(deep[top[u]]<deep[top[v]])
		swap(u,v);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	return u;
}
int sta[maxn];
int down(int st,int ed)
{
	int ans=0,len=0,tp=0;
	while(top[ed]!=top[ed]){
		sta[++tp]=ed;
		ed=fa[top[ed]];
	}
	seg t=query_lmax(1,tid[st],tid[ed]);
	len=t.sum,ans=t.lmax;
	for(int i=tp;i>=1;i--){
		t=query_lmax(1,tid[top[sta[i]]],tid[sta[i]]);
		ans=max(ans,len+t.rmax);
		len+=t.sum;
	}
	return ans;
}
int up(int st,int md,int ed)
{
	int len=0,ans=0;
	seg t;
	while(top[st]!=top[md]){
		t=query_rmax(1,tid[top[st]],tid[st]);
		ans=max(ans,len+t.rmax);
		len+=t.sum;
		st=fa[top[st]];
	}
	t=query_rmax(1,tid[md],tid[st]);
	ans=max(ans,len+t.rmax);
	len+=t.sum;
	ans=max(ans,len+down(md,ed));
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1,u,v,w;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),add(u,v,w),add(v,u,w);
	dfs(1,1),dfs2(1,1),build(1,1,n);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		int t1=lca(u,s),t2=lca(v,s),t3=lca(u,v),p,flag,d=dis[u]+dis[v]-2*dis[t3];
		if(deep[t1]>deep[t2])p=t1,flag=1;
		else if(deep[t1]<deep[t2])p=t2,flag=0;
		else p=t3,flag=1;
		if(flag==1)printf("%d\n",d-max(down(p,u),up(p,t3,v)));
		else printf("%d\n",d-max(down(p,v),up(p,t3,u)));
	}
	return 0;
}
