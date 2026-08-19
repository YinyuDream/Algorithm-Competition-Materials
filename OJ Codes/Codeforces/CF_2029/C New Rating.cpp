#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    auto trans=[&](int a,int b){
        if(a<b){
            return 1;
        }else if(a>b){
            return -1;
        }else{
            return 0;
        }
    };
    vector<array<int,3>> dp(n+1);
    dp[0][1]=dp[0][2]=-1e9;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+trans(dp[i-1][0],a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
        dp[i][2]=max(dp[i-1][2]+trans(dp[i-1][2],a[i]),dp[i-1][1]+trans(dp[i-1][1],a[i]));
    }
    cout<<max(dp[n][1],dp[n][2])<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}