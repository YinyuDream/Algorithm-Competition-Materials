#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a%2+b%2+c%2==3){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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