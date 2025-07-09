#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
ll m,c,d;
ll a[maxn],b[maxn];
class treap {
private:
    struct node {
        node *l, *r;
        int sz, key;
        ll val;

        node(ll v) : l(nullptr), r(nullptr), sz(1), key(rand()), val(v) {}
    };

    node* root;
    int cnt;

    void update(node* n) {
        if (n) {
            n->sz = (n->l ? n->l->sz : 0) + (n->r ? n->r->sz : 0) + 1;
        }
    }

    void split(node* now, ll val, node*& x, node*& y) {
        if (!now) {
            x = y = nullptr;
            return;
        }
        if (now->val <= val) {
            x = now;
            split(now->r, val, now->r, y);
        } else {
            y = now;
            split(now->l, val, x, now->l);
        }
        update(now);
    }

    node* merge(node* x, node* y) {
        if (!x || !y) return x ? x : y;
        if (x->key < y->key) {
            x->r = merge(x->r, y);
            update(x);
            return x;
        } else {
            y->l = merge(x, y->l);
            update(y);
            return y;
        }
    }

public:
    treap() : root(nullptr), cnt(0) {}

    void insert(ll val) {
        node* x;
        node* y;
        node* z;
        split(root, val, x, y);
        z = new node(val);
        root = merge(merge(x, z), y);
    }

    void erase(ll val) {
        node* x;
        node* y;
        node* z;
        split(root, val - 1, x, z);
        split(z, val, y, z);
        if (y) {
            y = merge(y->l, y->r);
        }
        root = merge(merge(x, y), z);
    }

    int size() {
        return root ? root->sz : 0;
    }

    int query(ll val) {
        node* x;
        node* y;
        split(root, val - 1, x, y);
        int res = x ? x->sz + 1 : 1;
        root = merge(x, y);
        return res;
    }
} st_in,st_out;
int read()
{
    int num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        num=num*10+ch-'0',ch=getchar();
    return num;
}
bool check(ll val,int pos)
{
    int cnt=0;
    cnt+=st_out.size()-(st_out.query(val)-1);
    cnt+=st_in.size()-(st_in.query(val+d*(pos-1))-1);
    return cnt>=k;
}
ll find(int pos)
{
    ll l=0,r=1e15;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid,pos))l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main(){
    srand((unsigned)time(0));
    n=read(),k=read(),m=read(),c=read(),d=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++)
        b[i]=a[i]+c+(i-1)*d;
    for(int i=1;i<=m;i++)
        st_in.insert(b[i]);
    for(int i=m+1;i<=n;i++)
        st_out.insert(a[i]);
    ll ans=find(1);
    for(int i=2;i+m-1<=n;i++){
        st_in.erase(b[i-1]);
        st_in.insert(b[i+m-1]);
        st_out.erase(a[i+m-1]);
        st_out.insert(a[i-1]);
        ans=max(ans,find(i));
    }
    cout<<ans<<endl;
    return 0;
}