#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int maxn=1e6+10;
set<ll> num;
vector<ll> v;
void solve(){
    ll n;
    cin>>n;
    int ans=upper_bound(v.begin(),v.end(),n)-v.begin();
    cout<<ans<<endl;
}
int main(){
    auto work=[&](ll k){
        i128 v0=0,v1=k;
        while(true){
            i128 v2=k*k*v1-v0;
            if(v2>1e18) break;
            num.insert(v2);
            v0=v1;
            v1=v2;
        }
    };
    num.insert(1);
    for(ll k=2;k<=1e6;k++){
        work(k);
    }
    for(auto x:num){
        v.push_back(x);
    }
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}