#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    ll tot=0;
    vector<ll> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
        sum[i]=sum[i-1]+a[i];
    }
    auto query=[&](int l,int r,int eth){
        int _eth=eth;
        eth=n-eth+1;
        ll ans=0;
        if(l<=min(r,eth)){
            ans+=sum[min(r,eth)+_eth-1]-sum[l+_eth-2];
        }
        if(r>=eth+1){
            ans+=sum[r-(eth+1)+1]-sum[max(l,eth+1)-(eth+1)];
        }
        return ans;
    };
    for(int i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        int u=(l-1)/n+1,v=(r-1)/n+1;
        if(u==v){
            cout<<query((l-1)%n+1,(r-1)%n+1,u)<<endl;
            continue;
        }
        ll ans=max(v-u-1,0)*tot;
        ans+=query((l-1)%n+1,n,u);
        ans+=query(1,(r-1)%n+1,v);
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