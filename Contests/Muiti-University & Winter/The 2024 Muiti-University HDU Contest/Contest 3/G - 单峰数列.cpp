#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x){
    putchar(x+'0');
}
struct node{
    int l,r,up,down;
    ll lazy,lval,rval;
};
class SegmentTree{
    public:
    SegmentTree(int n):n(n){
        tree.resize(4*n+1);
    }
    void build(vector<int> &a){
        build(1,1,n,a);
    }
    void update(int l,int r,int val){
        update(1,l,r,val);
    }
    ll query(int l,int r,int val){
        return query(1,l,r,val);
    }
    int nn(){
        return tree.size();
    }
    private:
    int n;
    vector<node> tree;
    void pushup(int p){
        tree[p].lval = tree[p<<1].lval;
        tree[p].rval = tree[p<<1|1].rval;
        tree[p].up = tree[p<<1].up+tree[p<<1|1].up-(tree[p<<1].rval<tree[p<<1|1].lval);
        tree[p].down = tree[p<<1].down+tree[p<<1|1].down-(tree[p<<1].rval>tree[p<<1|1].lval);
    }
    void pushdown(int p){
        if(tree[p].lazy){
            tree[p<<1].lval+=tree[p].lazy;
            tree[p<<1].rval+=tree[p].lazy;
            tree[p<<1].lazy+=tree[p].lazy;
            tree[p<<1|1].lval+=tree[p].lazy;
            tree[p<<1|1].rval+=tree[p].lazy;
            tree[p<<1|1].lazy+=tree[p].lazy;
            tree[p].lazy=0;
        }
    }
    void build(int p,int l,int r,vector<int> &a){
        tree[p].l = l,tree[p].r = r;
        if(l==r){
            tree[p].up = tree[p].down = 1;
            tree[p].lval = tree[p].rval = a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(p<<1,l,mid,a);
        build(p<<1|1,mid+1,r,a);
        pushup(p);
    }
    void update(int p,int l,int r,int val){
        if(tree[p].l==l&&tree[p].r==r){
            tree[p].lval+=val;
            tree[p].rval+=val;
            tree[p].lazy+=val;
            return;
        }
        pushdown(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid) update(p<<1,l,r,val);
        else if(l>mid) update(p<<1|1,l,r,val);
        else{
            update(p<<1,l,mid,val);
            update(p<<1|1,mid+1,r,val);
        }
        pushup(p);

    }
    int query(int p,int l,int r,int val){
        if(tree[p].l==l&&tree[p].r==r){
            if(val==1) return tree[p].up;
            else return tree[p].down;
        }
        pushdown(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid) return query(p<<1,l,r,val);
        else if(l>mid) return query(p<<1|1,l,r,val);
        else{
            if(val==1){
                return query(p<<1,l,mid,val)+query(p<<1|1,mid+1,r,val)-(tree[p<<1].rval<tree[p<<1|1].lval);
            }else{
                return query(p<<1,l,mid,val)+query(p<<1|1,mid+1,r,val)-(tree[p<<1].rval>tree[p<<1|1].lval);
            }
        }
    }
};
    
int main(){
    //freopen("1007.in","r",stdin);
    //freopen("1007.out","w",stdout);
    int n=read();
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) a[i]=read();
    SegmentTree tree(n);
    tree.build(a);
    int q=read();
    for(int i=1;i<=q;i++){
        int op,l,r;
        op=read(),l=read(),r=read();
        if(op==1){
            int x=read();
            tree.update(l,r,x);
        }else if(op==2){
            int up = tree.query(l,r,1);
            int down = tree.query(l,r,-1);
            write((up==r-l+1&&down==r-l+1));
            putchar('\n');
        }else if(op==3){
            write(tree.query(l,r,1)==1);
            putchar('\n');
        }else if(op==4){
            write(tree.query(l,r,-1)==1);
            putchar('\n');
        }else{
            int down=l+1,up=r;
            while(down<=up){
                int mid=(down+up)>>1;
                if(tree.query(l,mid,1)>1){
                    up=mid-1;
                }else{
                    down=mid+1;
                }
            }
            write(!(up<=l||up>=r||tree.query(up,r,-1)>1));
            putchar('\n');
        }
    }
    return 0;
}