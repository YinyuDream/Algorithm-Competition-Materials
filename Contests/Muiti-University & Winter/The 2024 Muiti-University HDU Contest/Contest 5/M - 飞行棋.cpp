#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    cout<<((n-1)*(n-1)%mod*ksm(n,mod-2)%mod+1)%mod<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}