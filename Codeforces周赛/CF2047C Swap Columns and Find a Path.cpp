#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(3,vector<int>(n+1));
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=-1e18;
    for(int i=1;i<=n;i++){
        ll val=a[1][i]+a[2][i];
        for(int j=1;j<i;j++){
            val+=max(a[1][j],a[2][j]);
        }
        for(int j=i+1;j<=n;j++){
            val+=max(a[1][j],a[2][j]);
        }
        ans=max(ans,val);
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