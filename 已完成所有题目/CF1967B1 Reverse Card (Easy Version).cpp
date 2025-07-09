#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n,m;
int main(){
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n>>m;
        for(ll i=1;i<=m;i++)
            ans+=max(0ll,(n+i)/(i*i));
        cout<<ans-1<<endl;
    }
    return 0;
}