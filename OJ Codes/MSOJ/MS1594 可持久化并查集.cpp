#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m,k,old,root[maxn];
struct node{
	int l,r,fa,deep;
}tree[maxn*28];
int build(int l,int r)
{
	int now=++k;
	if(l==r){
		tree[now].fa=l;
		return now;
	}
	int mid=(l+r)/2;
	tree[now].l=build(l,mid);
	tree[now].r=build(mid+1,r);
	return now;
}
int update(int pre,int l,int r,int x,int y)
{
	int now=++k;
	if(l==r){
		tree[now].fa=y;
		return now;
	}
	int mid=(l+r)/2;
	if(x<=mid)tree[now].l=update(tree[pre].l,l,mid,x,y),tree[now].r=tree[pre].r;
	else tree[now].r=update(tree[pre].r,mid+1,r,x,y),tree[now].l=tree[pre].l;
	return now;
}
int query(int now,int l,int r,int x)
{
	if(l==r)return now;
	int mid=(l+r)/2;
	if(x<=mid)return query(tree[now].l,l,mid,x);
	else return query(tree[now].r,mid+1,r,x);
}
int find(int now,int x)
{
	int fx=query(root[now],1,n,x);
	if(x==tree[fx].fa)return fx;
	else return find(now,tree[fx].fa);
}
void add(int now,int l,int r,int x)
{
	if(l==r){
		tree[now].deep++;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)add(tree[now].l,l,mid,x);
	else add(tree[now].r,mid+1,r,x);
}
int main(){
	scanf("%d%d",&n,&m);
	root[0]=build(1,n);
	for(int i=1,opt,x,y;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&y);
			int fx=find(i-1,x),fy=find(i-1,y);
			if(tree[fx].fa==tree[fy].fa){
				root[i]=root[i-1];
				continue;
			}else{
				if(tree[fx].deep>tree[fy].deep)
				swap(fx,fy);
				root[i]=update(root[i-1],1,n,tree[fx].fa,tree[fy].fa);
				if(tree[fx].deep==tree[fy].deep)
				add(root[i],1,n,tree[fy].fa);
			}
		}else if(opt==2){
			scanf("%d",&x);
			root[i]=root[x];
		}else{
			scanf("%d%d",&x,&y);
			root[i]=root[i-1];
			int fx=find(i,x),fy=find(i,y);
			if(tree[fx].fa==tree[fy].fa)puts("1");
			else puts("0");
		}
	}
	return 0;
}