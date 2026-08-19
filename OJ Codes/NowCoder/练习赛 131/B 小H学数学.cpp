#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int main(){
    int x,y;
    cin>>x>>y;
    vector<vector<int>> dp(y+2,vector<int>(2001));
    map<int,int> mp;
    for(int i=1;i<=10;i++){
        mp[i]=1;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            mp[i+j]++;
            mp[i-j]++;
        }
    }
    dp[0][0+1000]=1;
    for(int i=1;i<=y+1;i++){
        for(int j=-1000;j<=1000;j++){
            for(int k=-4;k<=10;k++){
                if(j-k+1000<=2000&&j-k+1000>=0){
                    dp[i][j+1000]=(dp[i][j+1000]+1ll*dp[i-1][j-k+1000]*mp[k])%p;
                }
                if(j+k+1000<=2000&&j+k+1000>=0){
                    dp[i][j+1000]=(dp[i][j+1000]+1ll*dp[i-1][j+k+1000]*mp[k])%p;
                }
            }
        }
    }
    cout<<dp[y+1][x+1000];
    return 0;
}