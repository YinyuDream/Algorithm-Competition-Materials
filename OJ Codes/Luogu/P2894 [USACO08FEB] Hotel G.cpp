#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt,q,root;
struct query{
	int len,opt;
}z[maxn];
struct node{
	int lson,rson,lmax,rmax,zmax,l,r,lazy,len;
}tree[maxn];
int build(int l,int r)
{
	int now=++cnt;
	tree[now].l=l,tree[now].r=r,tree[now].len=r-l+1;
	tree[now].lmax=tree[now].zmax=tree[now].rmax=tree[now].len;
	return now;
}
void pushup(int id)
{
	tree[id].zmax=max(tree[tree[id].lson].rmax+tree[tree[id].rson].lmax,max(tree[tree[id].lson].zmax,tree[tree[id].rson].zmax));
	tree[id].lmax=tree[tree[id].lson].lmax+(tree[tree[id].lson].lmax==tree[tree[id].lson].len)*tree[tree[id].rson].lmax;
	tree[id].rmax=tree[tree[id].rson].rmax+(tree[tree[id].rson].rmax==tree[tree[id].rson].len)*tree[tree[id].lson].rmax;
}
void pushdown(int id)
{
	if(tree[id].lazy==1){
		tree[tree[id].lson].lmax=tree[tree[id].lson].rmax=tree[tree[id].lson].zmax=0;
		tree[tree[id].rson].lmax=tree[tree[id].rson].rmax=tree[tree[id].rson].zmax=0;
		tree[tree[id].lson].lazy=tree[tree[id].rson].lazy=tree[id].lazy;
		tree[id].lazy=0;
	}else{
		tree[tree[id].lson].lmax=tree[tree[id].lson].rmax=tree[tree[id].lson].zmax=tree[tree[id].lson].len;
		tree[tree[id].rson].lmax=tree[tree[id].rson].rmax=tree[tree[id].rson].zmax=tree[tree[id].rson].len;
		tree[tree[id].lson].lazy=tree[tree[id].rson].lazy=tree[id].lazy;
		tree[id].lazy=0;
	}
}
void update(int id,int l,int r,int opt)
{
	if(tree[id].l==l&&tree[id].r==r){
		if(opt==1){
			tree[id].lazy=1;
			tree[id].lmax=tree[id].rmax=tree[id].zmax=0;
		}else{
			tree[id].lazy=-1;
			tree[id].lmax=tree[id].rmax=tree[id].zmax=tree[id].len;
		}
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(tree[id].lazy)pushdown(id);
	if(r<=mid)update(tree[id].lson,l,r,opt);
	else if(l>mid)update(tree[id].rson,l,r,opt);
	else update(tree[id].lson,l,mid,opt),update(tree[id].rson,mid+1,r,opt);
	pushup(id);
}
int query(int id,int l,int r,int k)
{
	if(tree[id].len==k)return tree[id].l;
	int mid=(tree[id].l+tree[id].r)/2;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(tree[id].lazy)pushdown(id);
	if(tree[tree[id].lson].zmax>=k)return query(tree[id].lson,l,r,k);
	else if(tree[tree[id].lson].rmax&&tree[tree[id].lson].rmax+tree[tree[id].rson].lmax>=k)return mid-tree[tree[id].lson].rmax+1;
	else if(tree[tree[id].rson].zmax>=k)return query(tree[id].rson,l,r,k);
	else return 0;
}
int main(){
	//freopen("hotel.in","r",stdin);
	//freopen("hotel.out","w",stdout);
	scanf("%d%d",&n,&m);
	root=build(1,n);
	for(int i=1,opt,d,x;i<=m;i++)
	{
		scanf("%d%d",&opt,&d);
		if(opt==1){
			int t=query(root,1,n,d);
			if(t)update(root,t,t+d-1,1);
			printf("%d\n",t);
		}else{
			scanf("%d",&x);
			update(root,d,x+d-1,0);
		}
	}
	return 0;
}