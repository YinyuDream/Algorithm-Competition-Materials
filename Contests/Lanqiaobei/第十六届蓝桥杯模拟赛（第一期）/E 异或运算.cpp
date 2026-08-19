#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[]={9226, 4690, 4873, 1285, 4624, 1596, 6982, 590, 8806, 121, 8399, 8526, 5426, 64, 9655, 7705, 3929, 3588, 7397, 8020, 1311, 5676, 3469, 2325, 1226, 8203, 9524, 3648, 5278, 8647};
int main(){
    ll ans=1e18;
    for(ll i=0;i<16384;i++){
        ll sum=0;
        for(int j=0;j<30;j++){
            sum+=(a[j]^i)*(a[j]^i);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}