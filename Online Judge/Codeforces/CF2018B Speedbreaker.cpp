#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),can(n+1);
    vector<vector<int>> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
        can[i]=1;
    }
    int mn=n+1,mx=0;
    int low=0,up=n+1;
    for(int i=1;i<=n;i++){
        if(pos[i].empty()){
            continue;
        }
        for(auto x:pos[i]){
            mn=min(mn,x);
            mx=max(mx,x);
        }
        if(mx-mn+1>i){
            cout<<0<<endl;
            return;
        }
        int delta=i-(mx-mn+1);
        low=max(low,mn-delta-1);
        up=min(up,mx+delta+1);
    }
    for(int i=1;i<=low;i++){
        can[i]=0;
    }
    for(int i=up;i<=n;i++){
        can[i]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=can[i];
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