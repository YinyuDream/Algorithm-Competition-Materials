#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    __int128 n;
    ll _n;
    cin>>_n;
    n=_n;
    __int128 l=1,r=2e18;
    auto check=[&](__int128 x){
        __int128 l=1,r=x;
        while(l<=r){
            __int128 mid=(l+r)>>1;
            if(mid>4e9||mid*mid>x)r=mid-1;
            else l=mid+1;
        }
        __int128 val=l-1;
        return x-val<n;
    };
    while(l<=r){
        __int128 mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    ll _l=l;
    cout<<_l<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}