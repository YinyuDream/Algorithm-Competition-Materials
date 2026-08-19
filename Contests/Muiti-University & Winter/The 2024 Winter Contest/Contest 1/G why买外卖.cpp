#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    ll m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(n);
    for(auto &[x,y]:a){
        cin>>x>>y;
    }
    sort(a.begin(),a.end(),[&](pair<ll,ll> u,pair<ll,ll> v){
        return u.first<v.first;
    });
    ll ans=m;
    for(auto [x,y]:a){
        m+=y;
        if(m>=x){
            ans=m;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}