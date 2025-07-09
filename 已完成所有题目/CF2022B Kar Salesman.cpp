#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x;
    cin>>n>>x;
    ll sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=(sum+x-1)/x;
    ll mx=*max_element(a.begin(),a.end());
    ans=max(ans,mx);
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