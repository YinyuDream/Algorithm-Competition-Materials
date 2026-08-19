#include<cstdio>
#include<algorithm>
//#include<windows.h>
#define f() puts("Debug")
using namespace std;
const int maxn=1e6+10;
int n,m,k,root;
struct node{
	int son[2],fa,size,val,max_val,lazy[2];//lazy0:add,lazy1:rev
}tree[maxn];
void update(int x)
{
	tree[x].size=tree[tree[x].son[0]].size+tree[tree[x].son[1]].size+1;
	tree[x].max_val=max(max(tree[tree[x].son[0]].max_val,tree[tree[x].son[1]].max_val),tree[x].val);
}
void pushdown(int x)
{
	if(tree[x].lazy[0]){
		if(tree[x].son[0])
		tree[tree[x].son[0]].lazy[0]+=tree[x].lazy[0],
		tree[tree[x].son[0]].max_val+=tree[x].lazy[0],
		tree[tree[x].son[0]].val+=tree[x].lazy[0];
		if(tree[x].son[1])
		tree[tree[x].son[1]].lazy[0]+=tree[x].lazy[0],
		tree[tree[x].son[1]].max_val+=tree[x].lazy[0],
		tree[tree[x].son[1]].val+=tree[x].lazy[0];
		tree[x].lazy[0]=0;
	}
	if(tree[x].lazy[1]){
		if(tree[x].son[0])
		tree[tree[x].son[0]].lazy[1]^=tree[x].lazy[1],
		swap(tree[x].son[0],tree[x].son[1]);
		if(tree[x].son[1])
		tree[tree[x].son[1]].lazy[1]^=tree[x].lazy[1],
		swap(tree[x].son[0],tree[x].son[1]);
		tree[x].lazy[1]=0;
	}
}
int build(int fa,int l,int r)
{
	//printf("%d   %d\n",l,r);
	int t=++k,mid=(l+r)/2;
	if(l==r){
		tree[t].fa=fa;tree[t].size=1;
		return t;
	}else if(l+1==r){
		tree[t].son[0]=build(t,l,l);
	}else{
		tree[t].son[0]=build(t,l,mid-1);
		tree[t].son[1]=build(t,mid+1,r);
	}
	tree[t].fa=fa;
	update(t);
	return t;
}
void rotate(int x)
{
	int y=tree[x].fa,z=tree[y].fa;
	if(tree[y].lazy[0]||tree[y].lazy[1])pushdown(y);
	if(tree[x].lazy[0]||tree[x].lazy[1])pushdown(x);
	int k=tree[y].son[1]==x;
	tree[z].son[tree[z].son[1]==y]=x;
	tree[x].fa=z;
	tree[y].son[k]=tree[x].son[k^1];
	tree[tree[x].son[k^1]].fa=y;
	tree[x].son[k^1]=y;
	tree[y].fa=x;
	update(y);
	update(x);
}
void splay(int x,int goal)
{
	while(tree[x].fa!=goal){
		int y=tree[x].fa,z=tree[y].fa;
		if(z!=goal){
			if((tree[z].son[0]==y)^(tree[y].son[0]==x))
			rotate(x);
			else
			rotate(y);
		}
		rotate(x);
	}
	if(goal==0)
	root=x;
}
void search(int x)
{
	int now=root;
	while(tree[tree[now].son[0]].size+1!=x)
	{
		//if(tree[now].lazy[0]||tree[now].lazy[1])pushdown(now);
		if(x>tree[tree[now].son[0]].size+1)x-=tree[tree[now].son[0]].size+1,now=tree[now].son[1];
		else now=tree[now].son[0];//printf("%d\n",now),Sleep(500);
	}
	splay(now,0);
}
int pre(int x)
{
	search(x);
	int now=tree[root].son[0];
	while(tree[now].son[1])
	now=tree[now].son[1];
	return now;
}
int net(int x)
{
	search(x);
	int now=tree[root].son[1];
	while(tree[now].son[0])
	now=tree[now].son[0];
	return now;
}
int get(int l,int r)
{
	int t1=pre(l),t2=net(r);
	splay(t1,0),splay(t2,t1);
	return tree[tree[root].son[1]].son[0];
}
void add(int l,int r,int val)
{
	int tmp=get(l,r);
	tree[tmp].lazy[0]+=val;
	splay(tmp,0);
}
void rev(int l,int r)
{
	int tmp=get(l,r);
	tree[tmp].lazy[1]^=1;
	swap(tree[tmp].son[0],tree[tmp].son[1]);
	update(tree[root].son[1]);
	update(root);
	splay(tmp,0);	
} 
int query(int l,int r)
{
	int tmp=get(l,r),ans=tree[tmp].max_val;
	splay(tmp,0);
	return ans;
}
void dfs(int u){
	if(tree[u].son[0])dfs(tree[u].son[0]);
	printf("%d\n",u);
	if(tree[u].son[1])dfs(tree[u].son[1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	root=build(0,0,n+1);
	for(int i=1;i<=m;i++)
	{
		int opt,l,r,val;//dfs(root);
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&l,&r,&val);
			add(l+1,r+1,val);
		}
		else if(opt==2)
		{
			scanf("%d%d",&l,&r);
			rev(l+1,r+1);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l+1,r+1));
		}
		
	}
	return 0;
}
