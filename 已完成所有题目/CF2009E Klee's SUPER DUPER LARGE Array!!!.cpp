#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;

void solve(){
    ll n,k;
    cin>>n>>k;
    auto sum=[&](ll l,ll r){
        if(l>r) return 0ll;
        ll len=r-l+1;
        ll a1=k+l-1,a2=k+r-1;
        return len*(a1+a2)/2;
    };
    auto val=[&](ll pos){
        return sum(1,pos)-sum(pos+1,n);
    };
    ll l=1,r=n;
    while(l<=r){
        
        ll mid=(l+r)>>1;
        if(val(mid)>=0){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    ll ans=1e18;
    for(ll i=max(1ll,l-5);i<=min(n,l+5);i++){
        ans=min(ans,abs(val(i)));
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