#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        ll k=min(max(b-a,0ll),1ll*n);
        ll ans=a*(n-k)+b*k-k*(k-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}