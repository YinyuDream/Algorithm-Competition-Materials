#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
char s[]={'a','e','i','o','u'};
void solve(){
    int n;
    cin>>n;
    vector<char> ans;
    for(int i=0;i<n;i++){
        ans.push_back(s[i%5]);
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x;
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