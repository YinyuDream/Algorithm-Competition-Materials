#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),p(n+1);
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[i]=(ch=='L'?-1:1);
    }
    vector<vector<int>> mx(n+1,vector<int>(20)),mn(n+1,vector<int>(20));
    for(int i=0;i<=n;i++){
        mx[i][0]=p[i];
        mn[i][0]=p[i];
    }
    for(int j=1;j<20;j++){
        for(int i=0;i+(1<<j)-1<=n;i++){
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
    auto query=[&](int l,int r){
        int k=log2(r-l+1);
        return make_pair(max(mx[l][k],mx[r-(1<<k)+1][k]),min(mn[l][k],mn[r-(1<<k)+1][k]));
    };
    int lst=0,up=0;
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        int l=min(i+a[i],i);
        int r=max(i+a[i],i);
        if(l>up){
            st.insert({lst,up});
            lst=i;
        }
        up=max(up,r);
    } 
    if(lst<=n){
        st.insert({lst,n}); 
    }
    st.erase({0,0});
    auto check=[&](int l,int r){
        auto [mx,mn]=query(l,r);
        return mx==r&&mn==l;
    };
    int cnt=0;
    for(auto [l,r]:st){
        cnt+=check(l,r);
    } 
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        auto it=prev(st.upper_bound({x,n+1}));
        auto [l,r]=*it;
        if(a[x]==-1){
            if(x==r){
                auto nxt=next(it);
                auto [l2,r2]=*nxt;
                cnt-=check(l,r);
                st.erase(it);
                cnt-=check(l2,r2);
                st.erase(nxt);
                if(a[x-1]==-1){
                    cnt+=check(l,r-1);
                    st.insert({l,r-1});
                    cnt+=check(r,r2);
                    st.insert({r,r2});
                }else{
                    cnt+=check(l,r2);
                    st.insert({l,r2});
                }
            }else{
                cnt-=check(l,r);
                st.erase(it);
                if(a[x-1]==-1){
                    cnt+=check(l,x-1);
                    st.insert({l,x-1});
                    cnt+=check(x,r);
                    st.insert({x,r});
                }else{
                    cnt+=check(l,r);
                    st.insert({l,r});
                }
            }
        }else{
            if(x==l){
                auto pre=prev(it);
                auto [l2,r2]=*pre;
                cnt-=check(l,r);
                st.erase(it);
                cnt-=check(l2,r2);
                st.erase(pre);
                if(a[x+1]==1){
                    cnt+=check(l+1,r);
                    st.insert({l+1,r});
                    cnt+=check(l2,l);
                    st.insert({l2,l});
                }else{
                    cnt+=check(l2,r);
                    st.insert({l2,r});
                }
            }else{
                cnt-=check(l,r);
                st.erase(it);
                if(a[x+1]==1){
                    cnt+=check(l,x);
                    st.insert({l,x});
                    cnt+=check(x+1,r);
                    st.insert({x+1,r});
                }else{
                    cnt+=check(l,r);
                    st.insert({l,r});
                }
            }
        }
        a[x]=-a[x];
        if(cnt==st.size()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
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