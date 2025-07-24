#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int a,b;
    cin>>a>>b;
    if(a%2!=0){
        cout<<"NO"<<endl;
    }else{
        if(a!=0){
            cout<<"YES"<<endl;
        }else{
            if(b%2==0){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
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