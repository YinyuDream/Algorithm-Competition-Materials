#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<n-i+1<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}