#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    ll u,v;
    cin>>n>>u>>v;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    ll gcd=__gcd(u,v);
    vector<ll> low(n),high(n);
    for(int i=1;i<n;i++){
        ll d=a[i]-a[0];
        ll val=d/gcd;
        low[i]=gcd*val-d;
        if(gcd*val!=d){
            high[i]=gcd*(val+1)-d;
        }else{
            high[i]=0;
        }
    }
    vector<pair<ll,ll>> p;
    for(int i=1;i<n;i++){
        if(low[i]&&high[i])
            p.push_back({high[i],low[i]});
    }
    if(p.size()==0){
        cout<<0<<endl;
        return;
    }
    sort(p.begin(),p.end(),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.first>b.first;
    });
    vector<ll> pre_mn(p.size()),suf_mx(p.size());
    for(int i=0;i<p.size();i++){
        if(i==0){
            pre_mn[i]=abs(p[i].second);
        }else{
            pre_mn[i]=max(pre_mn[i-1],abs(p[i].second));
        }
    }
    for(int i=p.size()-1;i>=0;i--){
        if(i==p.size()-1){
            suf_mx[i]=abs(p[i].first);
        }else{
            suf_mx[i]=max(suf_mx[i+1],abs(p[i].first));
        }
    }
    ll ans=1e18;
    ans=min(ans,pre_mn[p.size()-1]);
    ans=min(ans,suf_mx[0]);
    for(int i=1;i<p.size();i++)
        ans=min(ans,pre_mn[i-1]+suf_mx[i]);
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}