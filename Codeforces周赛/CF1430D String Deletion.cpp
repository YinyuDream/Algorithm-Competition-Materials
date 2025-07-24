#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    vector<int> pos;
    for(int i=1;i<=n;i++){
        if(pos.empty()||s[i]!=s[pos.back()]){
            pos.push_back(i);
        }
    }
    vector<int> seg;
    for(int i=1;i<pos.size();i++){
        seg.push_back(pos[i]-pos[i-1]);
    }
    seg.push_back(n-pos.back()+1);
    int ans=0,sz=0;
    for(auto x:seg){
        if(x>1){
            ans++;
            ans+=(sz+1)/2;
            sz=0;
        }else{
            sz++;
        }
    }
    cout<<ans+(sz+1)/2<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}