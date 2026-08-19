#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    if(n==1||n%4==0){
        cout<<"impossible"<<endl;
        return;
    }
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(0);
    int now=2;
    while(true){
        ans.push_back(now);
        ans.push_back(now+2);
        ans.push_back(now+1);
        ans.push_back(now+3);
        now+=4;
        if(now>=n){
            break;
        }
    }
    while(ans.back()>=n){
        ans.pop_back();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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