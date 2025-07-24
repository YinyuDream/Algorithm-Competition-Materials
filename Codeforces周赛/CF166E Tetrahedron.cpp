#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<array<ll,4>> dp(2);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i%2][0]=(dp[(i-1)%2][1]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;
        dp[i%2][1]=(dp[(i-1)%2][0]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%mod;
        dp[i%2][2]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][3])%mod;
        dp[i%2][3]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][2])%mod;
    }
    cout<<dp[n%2][0]<<endl;
    return 0;
}