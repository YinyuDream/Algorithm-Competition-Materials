#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"-1"<<endl;
        return ;
    }else{
        vector<int>ans;
        for(int i=1;i<=n/2;i++){
            ans.push_back(i);
            ans.push_back(n-i+1);
        }
        ans.push_back(n/2+1);
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
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