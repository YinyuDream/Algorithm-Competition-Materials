#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,root;
struct node{
	int l,r,size,val,key;
}tree[maxn*4];
int add(int x)
{
	int now=++k;
	tree[now].size=1;
	tree[now].val=x;
	tree[now].key=rand();
	return now;
}
void pushup(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
void split(int u,int val,int &l,int &r)
{
	if(!u){
		l=r=0;
		return;
	}
	if(tree[u].val<=val)l=u,split(tree[u].r,val,tree[u].r,r);
	else r=u,split(tree[u].l,val,l,tree[u].l);
	pushup(u);
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].key<tree[r].key){
		tree[l].r=merge(tree[l].r,r);
		pushup(l);
		return l;
	}else{
		tree[r].l=merge(l,tree[r].l);
		pushup(r);
		return r;
	}
}
int kth(int u,int _k)
{
	if(tree[tree[u].l].size>=_k)return kth(tree[u].l,_k);
	else if(tree[tree[u].l].size+1==_k)return tree[u].val;
	else return kth(tree[u].r,_k-tree[tree[u].l].size-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1,opt,num,l,r,p;i<=n;i++){
		scanf("%d%d",&opt,&num);
		if(opt==1){
			split(root,num-1,l,r);
			p=add(num);
			root=merge(merge(l,p),r);
		}else if(opt==2){
			split(root,num-1,l,r);
			split(r,num,p,r);
			p=merge(tree[p].l,tree[p].r);
			root=merge(merge(l,p),r);
		}else if(opt==3){
			split(root,num-1,l,r);
			printf("%d\n",tree[l].size+1);
			root=merge(l,r);
		}else if(opt==4){
			printf("%d\n",kth(root,num));
		}else if(opt==5){
			split(root,num-1,l,r);
			printf("%d\n",kth(l,tree[l].size));
			root=merge(l,r);
		}else{
			split(root,num,l,r);
			printf("%d\n",kth(r,1));
			root=merge(l,r);
		}
	}
	return 0;
}
