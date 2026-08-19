#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt,root;
struct node{
	int l,r,val,key,size;
}tree[maxn*4];
void pushup(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
void add(int val)
{
	tree[++cnt].val=val;
	tree[cnt].key=rand();
	tree[cnt].size=1;
}
void split(int u,int val,int &l,int &r)
{
	if(!u){
		l=r=0;
		return ;
	}
	if(tree[u].val<=val){
		l=u;
		split(tree[u].r,val,tree[u].r,r);
	}else{
		r=u;
		split(tree[u].l,val,l,tree[u].l);
	}
	pushup(u);
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].key<=tree[r].key){
		tree[l].r=merge(tree[l].r,r);
		pushup(l);
		return l;
	}else{
		tree[r].l=merge(l,tree[r].l);
		pushup(r);
		return r;
	}
}
int kth(int u,int k)
{
	if(tree[tree[u].l].size+1>k)return kth(tree[u].l,k);
	else if(tree[tree[u].l].size+1==k)return u;
	else return kth(tree[u].r,k-tree[tree[u].l].size-1);
}
int main(){
	//freopen("treap.in","r",stdin);
	//freopen("treap.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,opt,x,u,v;i<=n;i++)
	{
		scanf("%d%d",&opt,&x);
		if(opt==1){
			split(root,x,u,v);
			add(x);
			root=merge(merge(u,cnt),v);
		}else if(opt==2){
			int l,r;
			split(root,x,u,v);
			split(u,x-1,l,r);
			r=merge(tree[r].l,tree[r].r);
			root=merge(merge(l,r),v);
		}else if(opt==3){
			split(root,x-1,u,v);
			printf("%d\n",tree[u].size+1);
			root=merge(u,v);
		}else if(opt==4){
			printf("%d\n",tree[kth(root,x)].val);
		}else if(opt==5){
			split(root,x-1,u,v);
			printf("%d\n",tree[kth(u,tree[u].size)].val);
			root=merge(u,v);
		}else{
			split(root,x,u,v);
			printf("%d\n",tree[kth(v,1)].val);
			root=merge(u,v);
		}
		
	}
	return 0;
}