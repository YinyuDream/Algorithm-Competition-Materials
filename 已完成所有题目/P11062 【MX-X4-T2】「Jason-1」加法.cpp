#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll a,b;
    cin>>a>>b;
    if(a*b>=0){
        cout<<min({abs(-b),abs(a-b),abs(a)})<<endl;
    }else{
        cout<<0<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}