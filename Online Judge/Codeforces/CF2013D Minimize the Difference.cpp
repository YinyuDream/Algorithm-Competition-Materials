#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll a[maxn],sum[maxn];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct node{
    int l,r;
    ll mn,lazy,sum;
};
node tree[maxn];
void build(int id,int l,int r){
    tree[id].l=l,tree[id].r=r;
    tree[id].lazy=0;
    if(l==r){
        tree[id].mn=a[l];
        tree[id].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].mn=min(tree[id*2].mn,tree[id*2+1].mn);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void push_down(int id){
    if(tree[id].lazy){
        tree[id*2].mn=tree[id].lazy;
        tree[id*2].lazy=tree[id].lazy;
        tree[id*2+1].mn=tree[id].lazy;
        tree[id*2+1].lazy=tree[id].lazy;
        tree[id*2].sum=(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy;
        tree[id*2+1].sum=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy;
        tree[id].lazy=0;
    }
}
void update(int id,int l,int r,ll val){
    if(tree[id].l>r||tree[id].r<l) return;
    if(tree[id].l>=l&&tree[id].r<=r){
        tree[id].mn=val;
        tree[id].lazy=val;
        tree[id].sum=(tree[id].r-tree[id].l+1)*val;
        return;
    }
    push_down(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid) update(id*2,l,r,val);
    else if(l>mid) update(id*2+1,l,r,val);
    else{
        update(id*2,l,mid,val);
        update(id*2+1,mid+1,r,val);
    }
    tree[id].mn=min(tree[id*2].mn,tree[id*2+1].mn);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
ll query_min(int id,int l,int r){
    if(tree[id].l>r||tree[id].r<l) return LLONG_MAX;
    if(tree[id].l==l&&tree[id].r==r) return tree[id].mn;
    push_down(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid) return query_min(id*2,l,r);
    if(l>mid) return query_min(id*2+1,l,r);
    return min(query_min(id*2,l,r),query_min(id*2+1,l,r));
}
ll query_sum(int id,int l,int r){
    if(tree[id].l>r||tree[id].r<l) return 0;
    if(tree[id].l>=l&&tree[id].r<=r) return tree[id].sum;
    push_down(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid) return query_sum(id*2,l,r);
    if(l>mid) return query_sum(id*2+1,l,r);
    return query_sum(id*2,l,r)+query_sum(id*2+1,l,r);
}
void solve(){
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        //a[i]=read();
        a[i]=1e12/i;
    }
    build(1,1,n);
    auto check=[&](int l,int r){
        ll sum=query_sum(1,l,r);
        ll val=sum/(r-l+1);
        int rem=sum-(r-l+1)*val;
        return query_min(1,l,min({l,r-rem,r-1}))<val||query_min(1,r-rem+1,min(r-rem+1,r-1))<val+1;
    };
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i))l=mid+1;
            else r=mid-1;
        }
        int pos=l;
        ll tot=query_sum(1,pos,i);
        ll val=tot/(i-pos+1);
        int rem=tot-(i-pos+1)*val;
        update(1,pos,i-rem,val);
        update(1,i-rem+1,i,val+1);

    }
    write(query_sum(1,n,n)-query_sum(1,1,1));
    putchar('\n');
}
int main(){
    double start_time = clock();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    double end_time = clock();
    cout << "Time: " << (end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}