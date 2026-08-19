#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
long long data[maxn];
int n,m,r,k=0,tim=0;
int head[maxn];
int siz[maxn];//用来保存以x为根的子树节点个数
int top[maxn];//用来保存当前节点的所在链的顶端节点
int son[maxn];//用来保存重儿子
int dep[maxn];//用来保存当前节点的深度
int fa[maxn];//用来保存当前节点的父亲
int tid[maxn];//用来保存树中每个节点剖分后的新编号对应原来的点 
int pos[maxn];//用来保存当前节点在线段树中的位置
long long p;
struct node
{
	int to,next;
}edge[maxn*2];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
struct node2
{
	int left,right;
	long long sum,sign;
} tree[maxn*4];
void dfs1(int u,int father,int d)
{
	dep[u]=d;fa[u]=father;siz[u]=1;
	for(int i=head[u];i>0;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
	    if(son[u]==0 || siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)//tp表示u点所在重链的顶端节点
{
	top[u]=tp;
	pos[u]=++tim;
	tid[pos[u]]=u;
	if(son[u]==0) return;//没有孩子节点 
	dfs2(son[u],tp);
	for(int i=head[u];i>0;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=son[u] && v!=fa[u]) dfs2(v,v);
	}
}
void built(int id,int lef,int rig)//线段树建树 
{
	tree[id].left=lef;tree[id].right=rig;
	tree[id].sign=0;tree[id].sum=0;
	if(lef==rig) 
	{
		tree[id].sum=data[tid[lef]]%p;
		return;
	}
	int mid=(lef+rig)>>1;
	built(id*2,lef,mid);
	built(id*2+1,mid+1,rig);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
void downdata(int id)
{
	tree[id*2].sign=(tree[id*2].sign+tree[id].sign)%p;
	tree[id*2].sum=(tree[id*2].sum+(tree[id*2].right-tree[id*2].left+1)*tree[id].sign)%p;
	tree[id*2+1].sign=(tree[id*2+1].sign+tree[id].sign)%p;
	tree[id*2+1].sum=(tree[id*2+1].sum+(tree[id*2+1].right-tree[id*2+1].left+1)*tree[id].sign)%p;
	tree[id].sign=0;
}
void update(int id,int lef,int rig,long long val){
	if(tree[id].left>rig || tree[id].right<lef) return;
	if(tree[id].left>=lef && tree[id].right<=rig)
	{
		tree[id].sign=(tree[id].sign+val)%p;
		tree[id].sum=(tree[id].sum+(tree[id].right-tree[id].left+1)*val)%p;
		return;
	}
	if(tree[id].sign!=0) downdata(id);
	update(id*2,lef,rig,val);
	update(id*2+1,lef,rig,val);
	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
long long select(int id,int lef,int rig){
	if(tree[id].left>rig || tree[id].right<lef) return 0;
	if(tree[id].left>=lef && tree[id].right<=rig) return tree[id].sum%p;
	if(tree[id].sign!=0) downdata(id);
	return (select(id*2,lef,rig)+select(id*2+1,lef,rig))%p;
}
void trim(int x,int y,long long z{
	while(top[x]!=top[y])//不在一条重链上，即非连续一段区间 
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,pos[top[x]],pos[x],z);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);//同一条重链 
	update(1,pos[x],pos[y],z);
}
long long find(int x,int y)
{
	long long sum=0;
	while(top[x]!=top[y])//不在一条重链上，即非连续一段区间 
	{
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		sum=(sum+select(1,pos[top[x]],pos[x]))%p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);//同一条重链 
	sum=(sum+select(1,pos[x],pos[y]))%p;
	return sum;
}
int main()
{
	int u,v;
	int op,x,y;
	long long z;
	scanf("%d %d %d %lld",&n,&m,&r,&p);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&data[i]);
		data[i]=data[i]%p;
	}
	for(int i=1;i<n;i++) 
	{
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs1(r,r,0);
	dfs2(r,r);
	built(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d %d %lld",&x,&y,&z);
			trim(x,y,z);
		} else if(op==2){
			scanf("%d %d",&x,&y);
			printf("%lld\n",find(x,y));
		} else if(op==3){
			scanf("%d %lld",&x,&z);
			update(1,pos[x],pos[x]+siz[x]-1,z);
		} else {
			scanf("%d",&x);
			printf("%lld\n",select(1,pos[x],pos[x]+siz[x]-1));
		}
	}
	return 0;
} 
