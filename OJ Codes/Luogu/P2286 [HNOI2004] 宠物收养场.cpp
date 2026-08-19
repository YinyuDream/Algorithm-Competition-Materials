#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f,p=1e6;
int n,ans;
struct node{
	int l,r,key,val,size;
};
struct FHQ{
	int cnt,root;
	node tree[maxn];
	FHQ(){
		cnt=root=0;
		memset(tree,0,sizeof tree);
	}
	int size()
	{
		return tree[root].size;
	}
	void update(int id)
	{
		tree[id].size=tree[tree[id].l].size+tree[tree[id].r].size+1;
	}
	void add(int val)
	{
		tree[++cnt].val=val;
		tree[cnt].size=1;
		tree[cnt].key=rand();
		tree[cnt].l=tree[cnt].r=0;
	}
	void split(int id,int val,int &l,int &r)
	{
		if(!id){
			l=r=0;
			return ;
		}
		if(tree[id].val<=val){
			l=id;
			split(tree[id].r,val,tree[l].r,r);
		}else{
			r=id;
			split(tree[id].l,val,l,tree[r].l);
		}
		update(id);
	}
	int merge(int l,int r)
	{
		if(!l||!r)return l+r;
		if(tree[l].key<=tree[r].key){
			tree[l].r=merge(tree[l].r,r);
			update(l);
			return l;
		}else{
			tree[r].l=merge(l,tree[r].l);
			update(r);
			return r;
		}
	}
	int kth(int id,int k)
	{
		if(tree[tree[id].l].size>=k)return kth(tree[id].l,k);
		else if(tree[tree[id].l].size+1==k)return id;
		else return kth(tree[id].r,k-tree[tree[id].l].size-1);
	}
	void add_num(int x)//添加数x 
	{
		int l,r;
		split(root,x,l,r);
		add(x);
		root=merge(merge(l,cnt),r);
	}
	int del_num(int x)//删除离x最近的数 
	{
		int l,r;
		split(root,x-1,l,r);
		int t1=tree[kth(l,tree[l].size)].val;
		root=merge(l,r);
		split(root,x,l,r);
		int t2=tree[kth(r,1)].val,
			t3=tree[kth(l,tree[l].size)].val,p;
		root=merge(l,r);
		if(t3==x){
			split(root,x,l,r);
			split(l,x-1,l,p);
			root=merge(l,r);
			return 0;
		}else{
			if(abs(t1-x)>abs(t2-x)||(abs(t1-x)==abs(t2-x)&&t1>t2))
			swap(t1,t2);
			split(root,t1,l,r);
			split(l,t1-1,l,p);
			root=merge(l,r);
			return abs(x-t1);
		}
	}
}pet,person;
int main()
{
	person.add_num(inf),person.add_num(-inf);
	pet.add_num(inf),pet.add_num(-inf);
	scanf("%d",&n);
	for(int i=1,opt,x;i<=n;i++)
	{
		scanf("%d%d",&opt,&x);
		if(opt==0){
			if(person.size()==2)pet.add_num(x);
			else ans=(person.del_num(x)+ans)%p;
		}else{
			if(pet.size()==2)person.add_num(x);
			else ans=(pet.del_num(x)+ans)%p;
		}
	}
	printf("%d",ans);
	return 0;
}