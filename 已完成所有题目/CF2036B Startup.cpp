#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(k+1);
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        a[u]+=v;
    }
    vector<ll> val;
    for(int i=1;i<=k;i++){
        if(a[i]>0){
            val.push_back(a[i]);
        }
    }
    sort(val.begin(),val.end());
    ll ans=0;
    int sz=val.size();
    for(int i=sz-1;i>=0;i--){
        if(n>0){
            ans+=val[i];
            n--;
        }
        else{
            break;
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
    return 0;
}