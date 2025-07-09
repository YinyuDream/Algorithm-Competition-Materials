#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll x;
    cin>>x;
    if(x==0){
        cout<<"NO!"<<endl;
        return;
    }
    int ans=0;
    while((x&1)==0){
        ans++;
        x>>=1;
    }
    cout<<ans+1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}