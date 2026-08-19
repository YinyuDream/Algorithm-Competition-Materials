#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<count(s.begin(),s.end(),'1')<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cout<<i+1<<" "<<i+1<<endl;
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