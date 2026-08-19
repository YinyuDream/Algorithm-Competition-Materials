#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int n,m,p,k,cnt,t=N*8+5;
struct node{
	int to,next,wt;
}edge[N*12];
int head[N*12];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
struct segment_tree{
	int l,r;
}tree[N*12];
int leaf[N*12];//0:³öÊ÷£¬1:ÈëÊ÷ 
void build(int id,int l,int r,int opt)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		if(opt)add(id+4*N,id,0);
		else leaf[l]=id;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	opt?add(id+N*4,id*2+N*4,0),add(id+N*4,id*2+1+N*4,0):add(id*2,id,0),add(id*2+1,id,0);
	build(id*2,l,mid,opt),build(id*2+1,mid+1,r,opt);
}
void update_in(int id,int l,int r,int p)
{
	if(tree[id].l==l&&tree[id].r==r){
		add(p,id+4*N,0);
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update_in(id*2,l,r,p);
	else if(l>mid)update_in(id*2+1,l,r,p);
	else update_in(id*2,l,mid,p),update_in(id*2+1,mid+1,r,p);
}
void update_out(int id,int l,int r,int p)
{
	if(tree[id].l==l&&tree[id].r==r){
		add(id,p,1);
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update_out(id*2,l,r,p);
	else if(l>mid)update_out(id*2+1,l,r,p);
	else update_out(id*2,l,mid,p),update_out(id*2+1,mid+1,r,p);
}
priority_queue<pair<int,int> >q;
int book[N*12],dis[N*12];
void dij(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	build(1,1,n,0),build(1,1,n,1);
	for(int i=1,a,b,c,d;i<=m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		update_out(1,a,b,++t),update_in(1,c,d,t);
		update_out(1,c,d,++t),update_in(1,a,b,t);
	}
	dij(leaf[p]);
	for(int i=1;i<=n;i++)
		printf("%d\n",dis[leaf[i]]);
	return 0;
}
