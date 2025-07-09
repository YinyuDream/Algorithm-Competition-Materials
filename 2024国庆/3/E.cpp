#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    int mx=max(n,m)*2;
    vector<int> fac(mx+1,1),inv(mx+1,1),finv(mx+1,1);
    for(int i=2;i<=mx;i++)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[1]=1;
    for(int i=2;i<=mx;i++)
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=mx;i++)
        finv[i]=1ll*finv[i-1]*inv[i]%mod;
    auto C=[&](int x,int y){
        if(x<y) return 0ll;
        return 1ll*fac[x]*finv[y]%mod*finv[x-y]%mod;
    };
    s=" "+s;
    t=" "+t;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=0;i<=m;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=mod;
            if(s[i]!=t[j]){
                dp[i][j]-=dp[i-1][j-1];
                dp[i][j]%=mod;
                if(dp[i][j]<0){
                    dp[i][j]+=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]<t[j]){
                ans+=dp[i-1][j-1]*C(n-i+m-j,min(n-i,m-j))%mod;
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}