#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    int lim=(n+2)/2,mx=0;
    if(lim>=n){
        cout<<-1<<endl;
        return;
    }
    cout<<max(0ll,2*n*a[lim-1]-sum+1)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}