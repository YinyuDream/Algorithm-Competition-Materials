#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,m,p,k,cnt,t=N*8+5;
struct node{
	int to,next;
	ll wt;
}edge[N*12];
int head[N*12];
void add(int u,int v,ll w)
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
void update_out(int id,int l,int r,int p,ll wt)
{
	if(tree[id].l==l&&tree[id].r==r){
		add(id,p,wt);
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update_out(id*2,l,r,p,wt);
	else if(l>mid)update_out(id*2+1,l,r,p,wt);
	else update_out(id*2,l,mid,p,wt),update_out(id*2+1,mid+1,r,p,wt);
}
priority_queue<pair<ll,int> >q;
int book[N*12];
ll dis[N*12];
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
	for(int i=1,opt,a,b,c;i<=m;i++){
		ll w;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%lld",&a,&b,&w);
			update_out(1,a,a,++t,w),update_in(1,b,b,t);
		}else if(opt==2){
			scanf("%d%d%d%lld",&a,&b,&c,&w);
			update_out(1,a,a,++t,w),update_in(1,b,c,t);
		}else{
			scanf("%d%d%d%lld",&c,&a,&b,&w);
			update_out(1,a,b,++t,w),update_in(1,c,c,t);
		}
		
	}
	dij(leaf[p]);
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[leaf[i]]==0x3f3f3f3f3f3f3f3fll?-1:dis[leaf[i]]);
	return 0;
}
