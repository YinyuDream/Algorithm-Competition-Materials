#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void solve(){
    int n,q,cnt=0;
    cin>>n>>q;
    vector<int> a(n+1),len(n+1),fa(n+1);
    for(int i=2,_;i<=n;i++)
        cin>>_;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    auto count=[&](int pos){
        set<int> st1={a[pos]<<1,a[pos]<<1|1};
        set<int> st2={a[pos+1],a[pos+(len[pos]>>1)+1]};
        set<int> inter;
        set_intersection(st1.begin(),st1.end(),st2.begin(),st2.end(),inserter(inter,inter.begin()));
        return inter.size();
    };
    function<void(int,int)> init=[&](int l,int r){

        len[l]=r-l+1;
        if(l==r){
            return;
        }
        cnt+=count(l);
        fa[l+1]=fa[l+(len[l]>>1)+1]=l;
        init(l+1,l+(len[l]>>1));
        init(l+(len[l]>>1)+1,r);
    };
    init(1,n);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int tmp=a[x];
        if(len[x]>1)
            cnt-=count(x);
        if(fa[x])
            cnt-=count(fa[x]);
        a[x]=a[y];
        if(len[x]>1)
            cnt+=count(x);
        if(fa[x])
            cnt+=count(fa[x]);
        if(len[y]>1)
            cnt-=count(y);
        if(fa[y])
            cnt-=count(fa[y]);
        a[y]=tmp;
        if(len[y]>1)
            cnt+=count(y);
        if(fa[y])
            cnt+=count(fa[y]);
        if(cnt==n-1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
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