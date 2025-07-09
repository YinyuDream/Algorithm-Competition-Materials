#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll n,m,ans;
int main(){
    cin>>n>>m;
    for(ll i=0;i<60;i++){
        if(m&(1ll<<i)){
            ans+=(n>>i+1)<<i;
            ans%=p;
            if(n&(1ll<<i)){
                ans+=((n&((1ll<<i)-1))+1);
                ans%=p;
            }
        }
    }
    cout<<ans<<endl;
}