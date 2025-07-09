#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    auto ask=[&](ll val){
        cout<<"? "<<val<<endl;
        cout.flush();
        ll res;
        cin>>res;
        return res;
    };
    ll l=2,r=1e17;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(ask(mid)==mid){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<"! "<<l<<endl;
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}