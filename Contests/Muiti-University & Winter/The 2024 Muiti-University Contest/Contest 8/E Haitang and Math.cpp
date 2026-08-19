#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int digitSum(long long m) {
    int sum = 0;
    while (m > 0) {
        sum += m % 10;
        m /= 10;
    }
    return sum;
}
 
void solve(){
    ll n;
    cin>>n;
    ll count=0;
    for (int s = 1; s <= 108; ++s) {
        ll nn=n-s;
        for(ll i=1;i*i<=nn;i++){
            if(nn%i==0){
                ll t=nn/i;
                if(digitSum(t)==s){
                    if(n<t*(i+1)){
                        count++;
                    }
                }
                if(t!=i){
                    if(digitSum(i)==s){
                        if(n<i*(t+1)){
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout<<count<<'\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}