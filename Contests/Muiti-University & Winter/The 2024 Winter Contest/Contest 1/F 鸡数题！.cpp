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
    init();
    ll n,m;
    cin>>n>>m;
    if(m>n){
        cout<<0<<endl;
        return 0;
    }
    ll now=qpow(m,n);
    for(int j=m-1,sign=-1;j;j--){
        now=(now+sign*C(m,m-j)%mod*qpow(j,n))%mod;
        sign=-sign;
    }
    now=now*facinv[m]%mod;
    cout<<(now%mod+mod)%mod<<endl;   
    return 0;
}