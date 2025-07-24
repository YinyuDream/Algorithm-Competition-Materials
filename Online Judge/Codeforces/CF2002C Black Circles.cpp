#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn=1e6+10;
ll dis_cal(pii a,pii b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void solve(){
    int n;
    cin>>n;
    vector<pii> a(n);
    pii s,t;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    cin>>s.first>>s.second>>t.first>>t.second;
    ll dis=dis_cal(s,t);
    for(int i=0;i<n;i++){
        if(dis_cal(a[i],t)<=dis){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}