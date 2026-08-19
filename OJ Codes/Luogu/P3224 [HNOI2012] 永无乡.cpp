#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,q;
int a[maxn],fa[maxn],root[maxn],size[maxn],pos[maxn];
struct segment_tree{
	int lson,rson,size;
}tree[maxn*30];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int build(int l,int r,int c)
{
	int now=++k;
	if(l==r){
		tree[now].size=1;
		return now;
	}
	int mid=(l+r)/2;
	if(c<=mid)tree[now].lson=build(l,mid,c);
	else tree[now].rson=build(mid+1,r,c);
	tree[now].size=tree[tree[now].lson].size+tree[tree[now].rson].size;
	return now;
}
int merge(int p,int q,int l,int r)
{
	if(!p||!q)return p+q;
	if(l==r){
		tree[p].size+=tree[q].size;
		return p;
	}
	int mid=(l+r)/2;
	tree[p].lson=merge(tree[p].lson,tree[q].lson,l,mid);
	tree[p].rson=merge(tree[p].rson,tree[q].rson,mid+1,r);
	tree[p].size=tree[tree[p].lson].size+tree[tree[p].rson].size;
	return p;
}
int query(int u,int l,int r,int kth)
{
	if(l==r)return l;
	int mid=(l+r)/2;
	if(tree[tree[u].lson].size>=kth)return query(tree[u].lson,l,mid,kth);
	else return query(tree[u].rson,mid+1,r,kth-tree[tree[u].lson].size);
}
void dfs(int u,int l,int r)
{
	printf("%d %d %d %d\n",u,tree[u].size,l,r);
	int mid=(l+r)/2;
	if(tree[u].lson)dfs(tree[u].lson,l,mid);
	if(tree[u].rson)dfs(tree[u].rson,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
		fa[i]=i;
		size[i]=1;
		root[i]=build(1,n,a[i]);
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			if(size[fx]<size[fy])
			swap(fx,fy);
			root[fx]=merge(root[fx],root[fy],1,n);
			fa[fy]=fx;
			size[fx]+=size[fy];
		}
	}
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;i++){
		char opt;
		scanf("\n%c %d%d",&opt,&x,&y);
		if(opt=='B'){
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				if(size[fx]<size[fy])
				swap(fx,fy);
				root[fx]=merge(root[fx],root[fy],1,n);
				fa[fy]=fx;
				size[fx]+=size[fy];
			}
		}else{
			int fx=find(x);
			printf("%d\n",y<=size[fx]?pos[query(root[fx],1,n,y)]:-1);
		}	
	}
	return 0;
}