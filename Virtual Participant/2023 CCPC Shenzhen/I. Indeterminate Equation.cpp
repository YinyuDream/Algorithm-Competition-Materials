#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
__int128 qpow(__int128 a,ll b){
    __int128 ans=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
bool check(ll x){
    ll val=sqrtl(x);
    return val*val==x;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    int ans=0;
    ll lim=pow(n,1.0/k);
    if(k>3){
        for(ll i=1;i<=lim;i++){
            ll l=1,r=pow(n/i+1,1.0/(k-1))+1-i;
            while(l<=r){
                ll mid=(l+r)/2;
                if(qpow(mid+i,k)-qpow(mid,k)<n){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            if(qpow(l+i,k)-qpow(l,k)==n) ans++;
        }
        cout<<ans<<endl;
    }else{
        for(ll i=1;i<=lim;i++){
            if(n%i!=0){
                continue;
            }
            if((n/i-i*i)%3!=0){
                continue;
            }
            ll x=i,y=(n/i-i*i)/3;
            ll in=x*x+4*y;
            if(!check(in)){
                continue;
            }
            ll val=sqrtl(in);
            if((val-x)%2!=0){
                continue;
            }
            ll x1=(val-x)/2;
            ll x2=(-val-x)/2;
            if(x1>0){
                ans++;
            }
            if(x2>0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}