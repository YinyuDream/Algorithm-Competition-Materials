#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
constexpr ll p=1e9+7;
ll inv[maxn],fac[maxn],facinv[maxn];
ll ksm(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll val=ksm(a,b/2);
    val=val*val%p;
    if(b&1){
        val=val*a%p;
    }
    return val;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    cout<<ksm(ksm(2,m)-2,n)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}