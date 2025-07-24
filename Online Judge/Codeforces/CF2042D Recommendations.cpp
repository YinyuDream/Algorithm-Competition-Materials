#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int l,r;
    int id;
};
void solve(){
    int n;
    cin>>n;
    vector<node> seg(n+1);
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        seg[i]={l,r,i};
        mp[{l,r}]++;
    }
    auto origin=seg;
    sort(seg.begin()+1,seg.end(),[](node a,node b){
        if(a.l==b.l){
            return a.r>b.r;
        }
        return a.l<b.l;
    });
    vector<int> mxr(n+1),mnl(n+1);
    set<int> q;
    for(int i=1;i<=n;i++){
        auto pos=q.lower_bound(seg[i].r);
        if(pos!=q.end()){
            mxr[seg[i].id]=*pos;
        }else{
            mxr[seg[i].id]=seg[i].r;
        }
        q.insert(seg[i].r);
    }
    q.clear();
    sort(seg.begin()+1,seg.end(),[](node a,node b){
        if(a.r==b.r){
            return a.l<b.l;
        }
        return a.r>b.r;
    });
    for(int i=1;i<=n;i++){
        if(i==1){
            mnl[seg[i].id]=seg[i].l;
            q.insert(seg[i].l);
            continue;
        }
        auto pos=q.upper_bound(seg[i].l);
        if(pos!=q.begin()){
            mnl[seg[i].id]=*(--pos);
        }else{
            mnl[seg[i].id]=seg[i].l;
        }
        q.insert(seg[i].l);
    }
    for(int i=1;i<=n;i++){
        int len=origin[i].r-origin[i].l+1;
        int rec=mxr[i]-mnl[i]+1;
        if(mp[{origin[i].l,origin[i].r}]>=2){
            rec=len;
        }
        cout<<rec-len<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}