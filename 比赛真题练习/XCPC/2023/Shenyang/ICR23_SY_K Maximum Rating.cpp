#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k,m,root,cnt_positive;
ll sum_negative;
int a[maxn];
struct node{
	int l,r,val,key,size;
    ll sum;
}tree[maxn];
void update(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
    tree[u].sum=tree[tree[u].l].sum+tree[tree[u].r].sum+tree[u].val;
}
void add(int x)
{
	++k;
	tree[k].size=1;
	tree[k].val=tree[k].sum=x;
	tree[k].key=rand();
	tree[k].l=tree[k].r=0;
}
void split(int u,int x,int &l,int &r)
{
	if(!u){
		l=r=0;
		return ;
	}
	if(tree[u].val<=x){
		l=u;
		split(tree[u].r,x,tree[l].r,r);
	}
	else{
		r=u;
		split(tree[u].l,x,l,tree[r].l);
	}
	update(u);
}
int merge(int l,int r)
{
	if(l==0||r==0)
	    return l+r;
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
int kth(int u,ll k)
{
    if(!u)return 0;
	if(k<=tree[tree[u].l].sum)return kth(tree[u].l,k);
	else if(k>=tree[tree[u].l].sum+tree[u].val)return tree[tree[u].l].size+kth(tree[u].r,k-tree[tree[u].l].sum-tree[u].val)+1;
    else return tree[tree[u].l].size;
}
void add_num(int x)
{
    int l=0,r=0;
    split(root,x,l,r);
	add(x);
	root=merge(merge(l,k),r);
}
void delete_num(int x)
{
    int p=0,l=0,r=0;
	split(root,x,l,p);
	split(l,x-1,l,r);
	r=merge(tree[r].l,tree[r].r);
	root=merge(merge(l,r),p);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            cnt_positive++;
            add_num(a[i]);
        }else{
            sum_negative+=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        int pos,val;
        cin>>pos>>val;
        if(a[pos]>0&&val>0){
            delete_num(a[pos]);
            add_num(val);
        }else if(a[pos]>0&&val<=0){
            delete_num(a[pos]);
            cnt_positive--;
            sum_negative+=val;
        }else if(a[pos]<=0&&val>0){
            add_num(val);
            cnt_positive++;
            sum_negative-=a[pos];
        }else{
            sum_negative+=val-a[pos];
        }
        a[pos]=val;
        cout<<kth(root,-sum_negative)+1<<endl;
    }
    return 0;
}