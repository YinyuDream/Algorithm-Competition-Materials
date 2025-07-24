#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,s,m;
    cin>>n>>s>>m;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    if(l[1]>=s){
        cout<<"YES"<<endl;
        return;
    }
    if(r[n]+s<=m){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(l[i+1]-r[i]>=s){
            cout<<"YES"<<endl;
            return;
        }
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