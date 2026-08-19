#include<cstdio>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int n,k,root;
struct node{
	int son[2],fa,size,cnt,val;
}tree[maxn];
void update(int x)
{
	tree[x].size=tree[tree[x].son[0]].size+tree[tree[x].son[1]].size+tree[x].cnt;
}
void rotate(int x)
{
	int y=tree[x].fa,z=tree[y].fa;
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
	while(tree[x].fa!=goal)
	{
		int y=tree[x].fa,z=tree[y].fa;
		if(z!=goal)
		{
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
void add(int x)
{
	int now=root,fa=0;
	while(now&&tree[now].val!=x)
	fa=now,now=tree[now].son[x>tree[now].val];
	if(now)
	tree[now].cnt++;
	else
	{
		now=++k;
		if(fa)
		tree[fa].son[x>tree[fa].val]=now;
		tree[k].size=tree[k].cnt=1;
		tree[k].val=x;
		tree[k].fa=fa;
	}
	splay(now,0);
}
void search(int x)
{
	int now=root;
	//if(!now)return ;
	while(tree[now].son[x>tree[now].val]&&tree[now].val!=x)
	now=tree[now].son[x>tree[now].val];
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
void del(int x)
{
	int t1=pre(x),t2=net(x);
	splay(t1,0),splay(t2,t1);
	int tmp=tree[tree[root].son[1]].son[0];
	if(tree[tmp].cnt>1){
		tree[tmp].cnt--;
		splay(tmp,0);
	}else{
		tree[tree[root].son[1]].son[0]=0;
		splay(tree[root].son[1],0);
	}
}
int find(int x,int now)
{	
	if(x<=tree[tree[now].son[0]].size)
	return find(x,tree[now].son[0]);
	else if(x<=tree[now].cnt+tree[tree[now].son[0]].size)
	return now;
	else
	return find(x-tree[tree[now].son[0]].size-tree[now].cnt,tree[now].son[1]);
}
int main()
{
	add(inf),add(-inf);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt==1)
		add(x);
		else if(opt==2)
		del(x);
		else if(opt==3)
		search(x),printf("%d\n",tree[tree[root].son[0]].size);
		else if(opt==4)
		printf("%d\n",tree[find(x+1,root)].val);
		else if(opt==5)	
		add(x),printf("%d\n",tree[pre(x)].val),del(x);
		else
		add(x),printf("%d\n",tree[net(x)].val),del(x);
	}
	return 0;
} 
