#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll n,m;
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
bool isprime(ll x){
    if(x==1) return false;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    ll num=n,ans=1;
    for(ll i=2;i*i<=num;i++){
        if(isprime(i)&&n%i==0){
            ans=ans*(i-1)%p*qpow(i,p-2)%p;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans*(n-1)%p*qpow(n,p-2)%p;
    cout<<ans*qpow(num,m)%p<<endl;
    return 0;
}