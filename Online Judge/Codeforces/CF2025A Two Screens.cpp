#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s,t;
    cin>>s>>t;
    int ans=s.size()+t.size();
    int mn=min(s.size(),t.size());
    int flag=0;
    for(int i=0;i<mn;i++){
        if(s[i]!=t[i]){
            break;
        }
        ans--;
        flag=1;
    }
    cout<<ans+flag<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}