#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll l,r,i,k;
    cin>>l>>r>>i>>k;
    auto xor_sum=[&](ll x){
        if(x%4==0){
            return x;
        }
        if(x%4==1){
            return 1ll;
        }
        if(x%4==2){
            return x+1;
        }
        return 0ll;
    };
    ll ans=xor_sum(r)^xor_sum(l-1);
    ll val=(1ll<<i);
    ll up=(r-k)/val;
    ll low=(l-k)/val;
    while(low*val+k<l){
        low++;
    }
    while((low-1)*val+k>=l){
        low--;
    }
    while(up*val+k>r){
        up--;
    }
    while((up+1)*val+k<=r){
        up++;
    }
    if(up>=low){
        ll now=xor_sum(up)^(low==0?0:xor_sum(low-1));
        now=(now<<i);
        if((up-low+1)%2==1){
            now^=k;
        }
        ans=ans^now;
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