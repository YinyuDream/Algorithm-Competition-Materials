#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9+7)
void solve(){
    ll q;
    cin>>q;
    ll now=0;
    ll len=0;
    stack<ll>s;
    while(q--){
        ll a,b;
        cin>>a>>b;
        for(ll i=0;i<a;i++){
            now+=mod;
            now-=(len-i)*s.top();
            now%=mod;
            s.pop();
        }
        len-=a;
        len+=1;
        now+=len*b;
        s.push(b);
        now%=mod;
        now+=mod;
        now%=mod;
        cout<<now<<'\n';
    }
}
int main(){
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}