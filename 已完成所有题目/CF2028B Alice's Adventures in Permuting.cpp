#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    if(b>=n){
        cout<<n<<endl;
        return;
    }
    if(a!=0){
        ll mx;
        if((n-b)%a==0){
            mx=(n-b)/a;
        }else{
            mx=(n-b)/a+1;
        }
        cout<<n-mx<<endl;
    }else{
        if(b>=n){
            cout<<n<<endl;
        }else if(b>=n-2){
            cout<<n-1<<endl;
        }else{
            cout<<-1<<endl;
        }
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