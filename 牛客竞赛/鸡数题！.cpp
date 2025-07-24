#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=1e9+7;
ll fac[maxn],inv[maxn],facinv[maxn];
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    inv[1]=1;
    for(int i=2;i<maxn;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    facinv[0]=1;
    for(int i=1;i<maxn;i++) facinv[i]=facinv[i-1]*inv[i]%mod;
}
ll C(ll n,ll m){
    if(n<m) return 0;
    return fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+C(m,i)*qpow(i,n)%mod*facinv[i]%mod)%mod;
    }
    cout<<ans<<endl;   
    return 0;
}