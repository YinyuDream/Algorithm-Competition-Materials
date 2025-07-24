#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]=='1'&&s[i+1]=='1'){
            cout<<"YES"<<endl;
            return ;
        }
    }
    if(s[0]=='1'||s[n-1]=='1'){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}