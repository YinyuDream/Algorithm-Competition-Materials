#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1),p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    ll inv1=ksm(10000,mod-2);
    vector<vector<ll>> dp(2,vector<ll>(1024));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<1024;j++){
            dp[i&1][j]=0;
            dp[i&1][j]=dp[(i-1)&1][j]*(10000-p[i])%mod*inv1%mod;
            dp[i&1][j]=(dp[i&1][j]+dp[(i-1)&1][j^a[i]]*p[i]%mod*inv1%mod)%mod;
        }
    }
    ll ans=0;
    for(int i=0;i<1024;i++){
        ans=(ans+i*i*dp[n&1][i])%mod;
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