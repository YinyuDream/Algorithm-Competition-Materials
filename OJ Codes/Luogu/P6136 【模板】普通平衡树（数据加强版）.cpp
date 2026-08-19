#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=2e6+10;
int n,m,cnt_node,root,lastans,ans;
int a[maxn];
struct node{
	int l,r,val,key,size;
}tree[maxn];
int add(int val)
{
	cnt_node++;
	tree[cnt_node].val=val;
	tree[cnt_node].key=rand();
	tree[cnt_node].size=1;
	return cnt_node;
}
int build(int l,int r,int key)
{
	if(l>r)return 0;
	int now=++cnt_node;
	int mid=(l+r)/2;
	tree[now].val=a[mid];
	tree[now].key=key;
	if(l==r){
		tree[now].size=1;
		return now;
	}
	tree[now].l=build(l,mid-1,key+1);
	tree[now].r=build(mid+1,r,key+1);
	tree[now].size=tree[tree[now].l].size+tree[tree[now].r].size+1;
	return now;
}
void split(int u,int val,int &l,int &r)
{
	if(!u){
		l=r=0;
		return ;
	}
	if(tree[u].val<=val)l=u,split(tree[u].r,val,tree[u].r,r);
	else r=u,split(tree[u].l,val,l,tree[u].l);
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].key<=tree[r].key){
		tree[l].r=merge(tree[l].r,r);
		tree[l].size=tree[tree[l].l].size+tree[tree[l].r].size+1;
		return l;
	}else{
		tree[r].l=merge(l,tree[r].l);
		tree[r].size=tree[tree[r].l].size+tree[tree[r].r].size+1;
		return r;
	}
}
int kth(int u,int k)
{
	if(tree[tree[u].l].size>=k)return kth(tree[u].l,k);
	else{
		if(tree[tree[u].l].size+1==k)return tree[u].val;
		else return kth(tree[u].r,k-tree[tree[u].l].size-1);
	}
}
int main(){
	srand((unsigned)time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	root=build(1,n,1);
	for(int i=1,opt,x,u,v;i<=m;i++)
	{
		scanf("%d%d",&opt,&x);
		x^=lastans;
		if(opt==1){
			int p;
			split(root,x,u,v);
			p=add(x);
			root=merge(merge(u,p),v);
		}else if(opt==2){
			int p,l,r;
			split(root,x-1,u,v);
			split(v,x,l,r);
			l=merge(tree[l].l,tree[l].r);
			root=merge(merge(u,l),r);
		}else if(opt==3){
			split(root,x-1,u,v);
			lastans=tree[u].size+1;
			root=merge(u,v);
			ans^=lastans;
		}else if(opt==4){
			lastans=kth(root,x);
			ans^=lastans;
		}else if(opt==5){
			split(root,x-1,u,v);
			lastans=kth(u,tree[u].size);
			root=merge(u,v);
			ans^=lastans;
		}else{
			split(root,x,u,v);
			lastans=kth(v,1);
			root=merge(u,v);
			ans^=lastans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
