#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> pwk(61);
    pwk[0]=1;
    int now=0;
    for(int i=1;i<=60;i++){
        pwk[i]=pwk[i-1]*k;
        if(pwk[i]>n){
            now=i;
            break;
        }
    }
    int ans=0;
    for(int i=now;i>=0;i--){
        if(n>=pwk[i]){
            ll tmp=n/pwk[i];
            ans+=tmp;
            n-=tmp*pwk[i];
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