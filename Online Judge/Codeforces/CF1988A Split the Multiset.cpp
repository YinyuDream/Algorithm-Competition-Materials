#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,ans=0;
    cin>>n>>k;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    while(n>1){
        n-=k-1;
        ans++;
    }
    cout<<ans<<endl;
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}