#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    pair<int,int> a,b;
    cin>>a.first>>a.second>>b.first>>b.second;
    if(a==b){
        cout<<"YES"<<endl;
        return;
    }
    if(a.second>=a.first&&b.second<=b.first) cout<<"NO"<<endl;
    else if(b.second>=b.first&&a.second<=a.first) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}