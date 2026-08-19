#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1e6+10;
int n,root,cnt;
struct node{
	int lson,rson,l,r,size,key;
}tree[maxn*4];
void update(int u)
{
	tree[u].size=tree[tree[u].lson].size+tree[tree[u].rson].size+1;
}
void add(int l,int r)
{
	cnt++;
	tree[cnt].l=l;
	tree[cnt].r=r;
	tree[cnt].size=1;
	tree[cnt].key=rand();
}
void split(int u,int val,int &l,int &r,int opt)
{
	if(!u){
		l=r=0;
		return ;
	}
	if(opt?(tree[u].r<val):(tree[u].l<=val)){
		l=u;
		split(tree[u].rson,val,tree[u].rson,r,opt);
	}else{
		r=u;
		split(tree[u].lson,val,l,tree[u].lson,opt);
	}
	update(u);
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].key<=tree[r].key){
		tree[l].rson=merge(tree[l].rson,r);
		update(l);
		return l;
	}else{
		tree[r].lson=merge(l,tree[r].lson);
		update(r);
		return r;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,_l,_r;i<=n;i++)
	{
		char opt;
		scanf("\n%c",&opt);
		if(opt=='A'){
			scanf("%d%d",&_l,&_r);
			int u,v,l,r;
			split(root,_l,u,v,1);
			split(v,_r,l,r,0);
			printf("%d\n",tree[l].size);
			add(_l,_r);
			root=merge(merge(u,cnt),r);
		}else{
			printf("%d\n",tree[root].size);
		}
	}
	return 0;
}
