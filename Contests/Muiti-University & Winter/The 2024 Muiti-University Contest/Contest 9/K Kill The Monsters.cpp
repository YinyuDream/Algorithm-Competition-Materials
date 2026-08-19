#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    priority_queue<int,vector<int>,less<int>>v;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        v.push(t);
    }
    ll ans=v.top();
    if(k==1){
        cout<<ans<<'\n';
        return;
    }
    ll tt=0;
    while(1){
        ll p=v.top();
        v.pop();
        p/=k;
        v.push(p);
        tt++;
        if(tt+v.top()<=ans){
            ans=v.top()+tt;
        }
        if(v.top()==0)break;
    }
    cout<<ans<<'\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) {
        solve();
    }
     
    return 0;
}