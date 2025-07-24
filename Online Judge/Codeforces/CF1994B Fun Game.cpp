#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        if(s[i]=='0'&&t[i]=='1'){
            cout<<"NO"<<endl;
            return;
        }
        if(s[i]=='1'){
            break;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}