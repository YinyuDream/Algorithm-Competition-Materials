#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)
            ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
class segment_tree{
    private:
    struct node{
        int l,r;
        ll mul,sum,lazy;
    };
    vector<node> tree;
    public:
    segment_tree(int n){
        tree.resize(4*n+1);
    }
    void build(int id,int l,int r,vector<ll> &a){
        tree[id].l=l;
        tree[id].r=r;
        if(l==r){
            tree[id].sum=tree[id].mul=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*id,l,mid,a);
        build(2*id+1,mid+1,r,a);
        tree[id].sum=(tree[2*id].sum+tree[2*id].mul*tree[2*id+1].sum)%p;
        tree[id].mul=tree[2*id].mul*tree[2*id+1].mul%p;
    }
    void push_down(int id){
        if(tree[id].lazy){
            tree[2*id].lazy=tree[id].lazy;
            tree[2*id+1].lazy=tree[id].lazy;
            if(tree[id].lazy!=1){
                int len=tree[2*id].r-tree[2*id].l+1;
                tree[2*id].sum=tree[id].lazy*(qpow(tree[id].lazy,len)-1)%p*qpow(tree[id].lazy-1,p-2)%p;
                tree[2*id].mul=qpow(tree[id].lazy,len);
                len=tree[2*id+1].r-tree[2*id+1].l+1;
                tree[2*id+1].sum=tree[id].lazy*(qpow(tree[id].lazy,len)-1)%p*qpow(tree[id].lazy-1,p-2)%p;
                tree[2*id].mul=qpow(tree[id].lazy,len);
            }else{
                int len=tree[2*id].r-tree[2*id].l+1;
                tree[2*id].sum=len;
                tree[2*id].mul=1;
                len=tree[2*id+1].r-tree[2*id+1].l+1;
                tree[2*id+1].sum=len;
                tree[2*id].mul=1;
            }
            tree[id].lazy=0;
        }
    }
    void update(int id,int l,int r,ll val){
        if(tree[id].l>=l&&tree[id].r<=r){
            int len=tree[id].r-tree[id].l+1;
            tree[id].sum=val*(qpow(val,len)-1)%p*qpow(val-1,p-2)%p;
            tree[id].mul=qpow(val,len);
            tree[id].lazy=val;
            return;
        }
        push_down(id);
        int mid=(tree[id].l+tree[id].r)/2;
        if(r<=mid){
            update(2*id,l,r,val);
        }else if(l>mid){
            update(2*id+1,l,r,val);
        }else{
            update(2*id,l,r,val);
            update(2*id+1,l,r,val);
        }
        tree[id].sum=(tree[2*id].sum+tree[2*id].mul*tree[2*id+1].sum)%p;
        tree[id].mul=tree[2*id].mul*tree[2*id+1].mul%p;
    }
    pair<ll,ll> query(int id,int l,int r){
        if(tree[id].l>=l&&tree[id].r<=r)
            return make_pair(tree[id].sum,tree[id].mul);
        push_down(id);
        int mid=(tree[id].l+tree[id].r)/2;
        ll ans_1=0,ans_2=0;
        if(r<=mid){
            return query(2*id,l,r);
        }else if(l>mid){
            return query(2*id+1,l,r);
        }else{
            auto ans_1=query(2*id,l,r);
            auto ans_2=query(2*id+1,l,r);
            return make_pair((ans_1.first+ans_1.second*ans_2.first)%p,ans_1.second*ans_2.second%p);
        }
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    segment_tree st(n);
    st.build(1,1,n,a);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            ll x;
            cin>>l>>r>>x;
            st.update(1,l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<st.query(1,l,r).first<<endl;
        }
    }
    return 0;
}