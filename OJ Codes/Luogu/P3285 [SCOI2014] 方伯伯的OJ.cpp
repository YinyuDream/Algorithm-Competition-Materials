#include<cstdio>
#include<map>
using namespace std;
const int maxn=1e6+10;
int n,m,lastans,k,_l,_r,root;
map<int,int>mp;
struct node{
	int l,r,lson,rson,size,val;
}tree[maxn*30];
int build(int l,int r)
{
	int now=++k;
	tree[now].l=l,tree[now].r=r;
	tree[now].size=max(0,min(n,r)-max(1,l)+1);
	return now;
}
int change(int id,int pos,int val)
{
	if(tree[id].l==tree[id].r){
		tree[id].val=val;
		if(val==0)tree[id].size=0;
		else mp[val]=pos;
		return 1;
	}
	int mid=(tree[id].l+tree[id].r+1)/2-1,ans=0;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(pos<=mid)ans=change(tree[id].lson,pos,val);
	else ans=change(tree[id].rson,pos,val)+tree[tree[id].lson].size;
	tree[id].size=tree[tree[id].lson].size+tree[tree[id].rson].size;
	return ans;
}
void add(int id,int pos,int val)
{
	if(tree[id].l==tree[id].r){
		tree[id].size=1;
		tree[id].val=val;
		mp[val]=pos;
		return ;
	}
	int mid=(tree[id].l+tree[id].r+1)/2-1;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(pos<=mid)add(tree[id].lson,pos,val);
	else add(tree[id].rson,pos,val);
	tree[id].size=tree[tree[id].lson].size+tree[tree[id].rson].size;
}
int query(int id,int pos)
{
	if(tree[id].l==tree[id].r){
		if(tree[id].val)return tree[id].val;
		else return tree[id].l;
	}
	int mid=(tree[id].l+tree[id].r+1)/2-1;
	if(!tree[id].lson)tree[id].lson=build(tree[id].l,mid);
	if(!tree[id].rson)tree[id].rson=build(mid+1,tree[id].r);
	if(pos<=tree[tree[id].lson].size)return query(tree[id].lson,pos);
	else return query(tree[id].rson,pos-tree[tree[id].lson].size);
}
int main(){
	scanf("%d%d",&n,&m);
	_r=n;
	root=build(-m,n+m);
	for(int i=1,opt,x,y;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&y);
			x-=lastans;
			y-=lastans;
			printf("%d\n",lastans=change(root,mp[x]?mp[x]:x,y));
		}else if(opt==2){
			scanf("%d",&x);
			x-=lastans;
			printf("%d\n",lastans=change(root,mp[x]?mp[x]:x,0));
			add(root,--_l,x);
		}else if(opt==3){
			scanf("%d",&x);
			x-=lastans;
			printf("%d\n",lastans=change(root,mp[x]?mp[x]:x,0));
			add(root,++_r,x);
		}else{
			scanf("%d",&x);
			x-=lastans;
			printf("%d\n",lastans=query(root,x));
		}
	}
	return 0;
}
