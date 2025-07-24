#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll n;
    cin>>n;
    auto count=[&](ll x){
        int cnt=0;
        while(x){
            cnt+=x&1;
            x>>=1;
        }
        return cnt;
    };
    int cnt=count(n);
    if(cnt==1){
        cout<<1<<endl<<n<<endl;
        return;
    }
    cout<<cnt+1<<endl;
    ll x=(1ll<<cnt)-1;
    for(int i=0;i<cnt;i++){
        ll y=x^(1ll<<(cnt-i-1)),ans=0;
        int now=0;
        for(int j=0;j<=60;j++){
            if(n&(1ll<<j)){
                ll val=(y>>now)&1;
                ans|=val<<j;
                now++;
            }
        }
        cout<<ans<<" ";
    }
    ll y=x,ans=0;
    int now=0;
    for(int j=0;j<=60;j++){
        if(n&(1ll<<j)){
            ll val=(y>>now)&1;
            ans|=val<<j;
            now++;
        }
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