#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,inf=(2<<31)-1;
int n,k,root[maxn];
struct node{
	int l,r,size,val,key;
}tree[30*maxn];
void update(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
int add(int x)
{
	++k;
	tree[k].size=1;
	tree[k].val=x;
	tree[k].key=rand();
	return k;
}
void split(int u,int x,int &l,int &r)
{
	if(u==0){
		l=r=0;
		return ;
	}
	if(x>=tree[u].val){
		l=++k;
		tree[l]=tree[u];
		split(tree[l].r,x,tree[l].r,r);
		update(l);
	}else{
		r=++k;
		tree[r]=tree[u];
		split(tree[r].l,x,l,tree[r].l);
		update(r);
	}
	//update(u);
}
int merge(int u,int v)
{
	if(!u||!v)
	return u+v;
	if(tree[u].key<=tree[v].key){
		int now=++k;
		tree[now]=tree[u];
		tree[now].r=merge(tree[now].r,v);
		update(now);
		return now;
	}else{
		int now=++k;
		tree[now]=tree[v];
		tree[now].l=merge(u,tree[now].l);
		update(now);
		return now;
	}
}
int kth(int u,int k)
{
	if(k<=tree[tree[u].l].size)
	return kth(tree[u].l,k);
	else
	{
		if(k==tree[tree[u].l].size+1)
		return tree[u].val;
		else
		return kth(tree[u].r,k-tree[tree[u].l].size-1);
	}
}
int main()
{
	scanf("%d",&n);
	//int t2=add(-inf),t1=add(inf);
	//root[0]=merge(t2,t1);
	for(int i=1;i<=n;i++)
	{
		int old,opt,x,l=0,r=0,p=0;
		scanf("%d%d%d",&old,&opt,&x);
		root[i]=root[old];
		if(opt==1)
		{
			split(root[i],x,l,r);
			p=add(x);
			root[i]=merge(merge(l,p),r);
		}
		else if(opt==2)
		{
			split(root[i],x,l,r);
			split(l,x-1,l,p);
			p=merge(tree[p].l,tree[p].r);
			root[i]=merge(merge(l,p),r);
		}
		else if(opt==3)
		{
			split(root[i],x-1,l,r);
			printf("%d\n",tree[l].size+1);
			root[i]=merge(l,r);
		}
		else if(opt==4)
		{
			printf("%d\n",kth(root[i],x));
		}
		else if(opt==5)
		{
			split(root[i],x-1,l,r);
			if(tree[l].size==0)
			printf("%d\n",-(2<<31)+1);
			else
			printf("%d\n",kth(l,tree[l].size));
			root[i]=merge(l,r);
		}
		else
		{
			split(root[i],x,l,r);
			if(tree[r].size==0)
			printf("%d\n",(2<<31)-1);
			else
			printf("%d\n",kth(r,1));
			root[i]=merge(l,r);
		}
	}
	return 0;
}
