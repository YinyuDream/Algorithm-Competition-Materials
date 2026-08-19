#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn=1e6+10,inf=0x3f3f3f3f;
int n,m,a[maxn],minx=inf;
vector<int>vec[maxn];
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
		else if(tree[tree[id].l].size+1==k)return tree[id].val;
		else return kth(tree[id].r,k-tree[tree[id].l].size-1);
	}
	void add_num(int x)
	{
		int l,r;
		split(root,x,l,r);
		add(x);
		root=merge(merge(l,cnt),r);
	}
	void del_num(int x)
	{
		int p,l,r,u,v;
		split(root,x-1,u,v);
		split(v,x,l,r);
		l=merge(tree[l].l,tree[l].r);
		root=merge(merge(u,l),r);
	}
	int find_min()
	{
		int now=root;
		while(tree[now].l)now=tree[now].l;
		return tree[now].val;
	}
	int pre(int x)
	{
		int u,v;
		split(root,x,u,v);
		int ans=kth(u,tree[u].size);
		root=merge(u,v);
		return ans;
	}
	int net(int x)
	{
		int u,v;
		split(root,x,u,v);
		int ans=kth(v,1);
		root=merge(u,v);
		return ans;
	}
}num,gap;
int query(int x)
{
	int t1=num.pre(x),t2=num.net(x);
	num.add_num(x);
	return min(abs(x-t1),abs(x-t2));
}
int main(){
	num.add_num(inf),num.add_num(-inf);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		vec[i].push_back(a[i]);
		minx=min(minx,query(a[i]));
	}
	for(int i=1;i<n;i++)
		gap.add_num(abs(a[i]-a[i+1]));
	for(int i=1,p,k;i<=m;i++)
	{
		string opt;
		cin>>opt;
		if(opt=="INSERT"){
			scanf("%d%d",&p,&k);
			if(p!=n)gap.del_num(abs(*(vec[p].end()-1)-*vec[p+1].begin()));
			vec[p].push_back(k);
			if(p!=n)gap.add_num(abs(*(vec[p].end()-1)-*vec[p+1].begin()));
			gap.add_num(abs(*(vec[p].end()-2)-*(vec[p].end()-1)));
			minx=min(minx,query(k));
		}else if(opt=="MIN_GAP")printf("%d\n",gap.find_min());
		else printf("%d\n",minx);
	}
	return 0;
}
