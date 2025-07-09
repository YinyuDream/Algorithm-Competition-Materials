#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int ans=0,tot=0;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(b<=k){
            ans+=a;
            tot+=b;
        }else{
            b-=k;
            v.push_back({a,b});
        }
    }
    int m=v.size(),lim=(n-m)*k-tot;
    vector<vector<int>> dp(m+1,vector<int>(lim+1));
    for(int j=0;j<=(n-m)*k-tot;j++)
            if(j-v[0].second>=0)
                    dp[0][j]=v[0].first;
    for(int i=1;i<m;i++){
        for(int j=0;j<=lim;j++){
            dp[i][j]=dp[i-1][j];
            if(j-v[i].second>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].second]+v[i].first);
            }
        }
    }
    cout<<dp[m-1][lim]+ans;
    return 0;
}