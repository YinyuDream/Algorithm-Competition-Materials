#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    vector<int> ans;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<4;j++){
            if(s[j]=='#'){
                ans.push_back(j+1);
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
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