#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,min_val,ans,cnt;
struct node{
	int l,r,key,val,size,lazy;
}tree[maxn];
void pushdown(int id)
{
	tree[tree[id].l].lazy+=tree[id].lazy;
	tree[tree[id].r].lazy+=tree[id].lazy;
	tree[tree[id].l].val+=tree[id].lazy;
	tree[tree[id].r].val+=tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id)
{
	tree[id].size=tree[tree[id].l].size+tree[tree[id].r].size+1;
}
void split(int id,int k,int &l,int &r)
{
	if(!id){
		l=r=0;
		return ;
	}
	if(tree[id].lazy)
	pushdown(id);
	if(tree[id].val<=k){
		l=id;
		split(tree[id].r,k,tree[l].r,r);
	}else{
		r=id;
		split(tree[id].l,k,l,tree[r].l);
	}
	update(id);
}
void add(int val)
{
	cnt++;
	tree[cnt].val=val;
	tree[cnt].key=rand();
	tree[cnt].l=tree[cnt].r=0;
	tree[cnt].size=1;
}
int merge(int l,int r)
{
	if(!l||!r)
	return l+r;
	if(tree[l].key<=tree[r].key)
	{
		if(tree[l].lazy)
		pushdown(l);
		tree[l].r=merge(tree[l].r,r);
		update(l);
		return l;
	}
	else
	{
		if(tree[r].lazy)
		pushdown(r);
		tree[r].l=merge(l,tree[r].l);
		update(r);
		return r;
	}
}
int kth(int id,int k)
{
	if(tree[tree[id].l].size+1==k)
	return tree[id].val;
	else{
		if(tree[id].lazy)
		pushdown(id);
		if(tree[tree[id].l].size>=k){
			return kth(tree[id].l,k);
		}else{
			return kth(tree[id].r,k-tree[tree[id].l].size-1);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&min_val);
	int root=0;
	for(int i=1;i<=n;i++)
	{
		char opt;
		int x,l,r;
		scanf("\n%c %d",&opt,&x);
		if(opt=='I')
		{
			if(x<min_val)continue;
			split(root,x,l,r);
			add(x);
			root=merge(merge(l,cnt),r);
		}
		else if(opt=='A')
		{
			tree[root].lazy+=x;
			tree[root].val+=x;
		}
		else if(opt=='S')
		{
			tree[root].lazy-=x;
			tree[root].val-=x;
			split(root,min_val-1,l,r);
			ans+=tree[l].size;
			root=r;
		}
		else
		{
			if(x>tree[root].size)puts("-1");
			else printf("%d\n",kth(root,tree[root].size-x+1));
		}
	}
	printf("%d",ans);
	return 0;
}