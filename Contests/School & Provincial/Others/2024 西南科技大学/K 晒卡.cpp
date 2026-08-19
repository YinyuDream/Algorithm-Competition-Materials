#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> cnt_a(1001),cnt_b(1001);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt_a[x]=1;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt_b[x]=1;
    }
    vector<int> ans;
    for(int i=1;i<=1000;i++){
        if(cnt_a[i]&&cnt_b[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()){
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
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