#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==a[n]){
        cout<<0<<endl;
        return;
    }
    vector<int> pos;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            pos.push_back(i);
        }
    }
    pos.push_back(n+1);
    int ans=n+1;
    for(int i=0;i<pos.size()-1;i++){
        int l=pos[i],r=pos[i+1]-1;
        ans=min(ans,l-1+n-r);
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}