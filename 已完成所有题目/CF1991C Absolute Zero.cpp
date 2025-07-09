#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans;
    auto check=[&](){
        sort(a.begin(),a.end());
        return a[n-1]!=0;
    };
    while(check()){
        ans.push_back((a[0]+a[n-1])/2);
        for(int i=0;i<n;i++){
            a[i]=abs(a[i]-ans.back());
        }
        if(ans.size()>40){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<" ";
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