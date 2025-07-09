#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class BIT{
private:
    int n;
    vector<int> tree;
public:
    BIT(int n):n(n){
        tree.resize(n+10);
    }
    int lowbit(int x){
        return x&-x;
    }
    void update(int pos,int val){
        for(int i=pos;i<=n;i+=lowbit(i)){
            tree[i]+=val;
        }
    }
    int query(int pos){
        int res=0;
        for(int i=pos;i;i-=lowbit(i)){
            res+=tree[i];
        }
        return res;
    }
    int query(int l,int r){
        if(l>r){
            return 0;
        }
        return query(r)-query(l-1);
    }
};
class seg_tr{
private:
    int n;
    struct node{
        int l,r,lazyl,lazyr,alle;
        ll suml,sumr,tot;
    };
    vector<node> tree;
public:
    seg_tr(int n):n(n){
        tree.resize(4*n+10);
    }
    void push_up(int id){
        tree[id].suml=tree[id*2].suml+tree[id*2+1].suml;
        tree[id].sumr=tree[id*2].sumr+tree[id*2+1].sumr;
        tree[id].tot=tree[id*2].tot+tree[id*2+1].tot;
        tree[id].alle=tree[id*2].alle+tree[id*2+1].alle;
    }
    void push_down(int id){
        tree[id*2].lazyl+=tree[id].lazyl;
        tree[id*2].lazyr+=tree[id].lazyr;
        tree[id*2+1].lazyl+=tree[id].lazyl;
        tree[id*2+1].lazyr+=tree[id].lazyr;
        tree[id*2].tot+=tree[id].lazyl*tree[id*2].sumr+tree[id].lazyr*tree[id*2].suml+1ll*tree[id].lazyl*tree[id].lazyr*tree[id*2].alle;
        tree[id*2+1].tot+=tree[id].lazyl*tree[id*2+1].sumr+tree[id].lazyr*tree[id*2+1].suml+1ll*tree[id].lazyl*tree[id].lazyr*tree[id*2+1].alle;
        tree[id*2].suml+=1ll*tree[id].lazyl*tree[id*2].alle;
        tree[id*2].sumr+=1ll*tree[id].lazyr*tree[id*2].alle;
        tree[id*2+1].suml+=1ll*tree[id].lazyl*tree[id*2+1].alle;
        tree[id*2+1].sumr+=1ll*tree[id].lazyr*tree[id*2+1].alle;
        tree[id].lazyl=tree[id].lazyr=0;
    }
    void build(int id,int l,int r,vector<int> &per,vector<int> &suf,string &s){
        tree[id].l=l;
        tree[id].r=r;
        if(l==r){
            if(s[l]=='e'){
                tree[id].suml=per[l-1];
                tree[id].sumr=suf[r+1];
                tree[id].tot=1ll*tree[id].suml*tree[id].sumr;
                tree[id].alle=1;
            }
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid,per,suf,s);
        build(id*2+1,mid+1,r,per,suf,s);
        push_up(id);
    }
    void update_l(int id,int l,int r,int val){
        
        if(tree[id].r<l||tree[id].l>r||l>r){
            return;
        }
        if(tree[id].l>=l&&tree[id].r<=r){
            tree[id].lazyl+=val;
            tree[id].suml+=val*tree[id].alle;
            tree[id].tot+=val*tree[id].sumr;
            return;
        }
        push_down(id);
        int mid=(tree[id].l+tree[id].r)/2;
        if(r<=mid){
            update_l(id*2,l,r,val);
        }else if(l>mid){
            update_l(id*2+1,l,r,val);
        }else{
            update_l(id*2,l,mid,val);
            update_l(id*2+1,mid+1,r,val);
        }
        push_up(id);
    }
    void update_r(int id,int l,int r,int val){
        
        if(tree[id].r<l||tree[id].l>r||l>r){
            return;
        }
        if(tree[id].l>=l&&tree[id].r<=r){
            tree[id].lazyr+=val;
            tree[id].sumr+=val*tree[id].alle;
            tree[id].tot+=val*tree[id].suml;
            return;
        }
        push_down(id);
        int mid=(tree[id].l+tree[id].r)/2;
        if(r<=mid){
            update_r(id*2,l,r,val);
        }else if(l>mid){
            update_r(id*2+1,l,r,val);
        }else{
            update_r(id*2,l,mid,val);
            update_r(id*2+1,mid+1,r,val);
        }
        push_up(id);
    }
    void update_p(int id,int pos,int val_l,int val_r){
        if(tree[id].l==tree[id].r){
            if(!tree[id].alle){
                tree[id].suml=val_l;
                tree[id].sumr=val_r;
                tree[id].tot=1ll*val_l*val_r;
            }else{
                tree[id].suml=tree[id].sumr=tree[id].tot=0;
            }
            tree[id].alle^=1;
            return;
        }
        push_down(id);
        int mid=(tree[id].l+tree[id].r)/2;
        if(pos<=mid){
            update_p(id*2,pos,val_l,val_r);
        }else{
            update_p(id*2+1,pos,val_l,val_r);
        }
        push_up(id);
    }
    ll query(){
        return tree[1].tot;
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    string s,t;
    cin>>s>>t;
    s=" "+s,t=" "+t;
    vector<int> per_s(n+2),suf_s(n+2);
    vector<int> per_t(n+2),suf_t(n+2);
    for(int i=1;i<=n;i++){
        per_s[i]=per_s[i-1]+(s[i]=='r');
        per_t[i]=per_t[i-1]+(t[i]=='r');
    }
    for(int i=n;i>=1;i--){
        suf_s[i]=suf_s[i+1]+(s[i]=='d');
        suf_t[i]=suf_t[i+1]+(t[i]=='d');
    }
    seg_tr trs(n),trt(n);
    trs.build(1,1,n,per_s,suf_s,s);
    trt.build(1,1,n,per_t,suf_t,t);
    BIT cnts_r(n),cnts_d(n);
    BIT cntt_r(n),cntt_d(n);
    for(int i=1;i<=n;i++){
        if(s[i]=='r'){
            cnts_r.update(i,1);
        }
        if(s[i]=='d'){
            cnts_d.update(i,1);
        }
    }
    for(int i=1;i<=n;i++){
        if(t[i]=='r'){
            cntt_r.update(i,1);
        }
        if(t[i]=='d'){
            cntt_d.update(i,1);
        }
    }
    while(q--){
        int pos;
        cin>>pos;
        if(s[pos]=='r'){
            cnts_r.update(pos,-1);
            trs.update_l(1,pos+1,n,-1);
            cntt_r.update(pos,1);
            trt.update_l(1,pos+1,n,1);
        }
        if(s[pos]=='e'){
            trs.update_p(1,pos,cnts_r.query(1,pos-1),cnts_d.query(pos+1,n));
            trt.update_p(1,pos,cntt_r.query(1,pos-1),cntt_d.query(pos+1,n));
        }
        if(s[pos]=='d'){
            cnts_d.update(pos,-1);
            trs.update_r(1,1,pos-1,-1);
            cntt_d.update(pos,1);
            trt.update_r(1,1,pos-1,1);
        }
        if(t[pos]=='r'){
            cntt_r.update(pos,-1);
            trt.update_l(1,pos+1,n,-1);
            cnts_r.update(pos,1);
            trs.update_l(1,pos+1,n,1);
        }
        if(t[pos]=='e'){
            trt.update_p(1,pos,cntt_r.query(1,pos-1),cntt_d.query(pos+1,n));
            trs.update_p(1,pos,cnts_r.query(1,pos-1),cnts_d.query(pos+1,n));
        }
        if(t[pos]=='d'){
            cntt_d.update(pos,-1);
            trt.update_r(1,1,pos-1,-1);
            cnts_d.update(pos,1);
            trs.update_r(1,1,pos-1,1);
        }
        swap(s[pos],t[pos]);
        cout<<trs.query()-trt.query()<<endl;
    }
    return 0;
}