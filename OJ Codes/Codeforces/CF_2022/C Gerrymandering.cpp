#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
int check(char a,char b,char c){
    return (a=='A')+(b=='A')+(c=='A')>=2;
}
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    s=" "+s;
    t=" "+t;
    vector<array<int,4>> dp(n+1,{-inf,-inf,-inf,-inf});
    dp[0][2]=dp[0][3]=0;
    for(int i=1;i<=n;i++){
        if(i-2>=0){
            dp[i][0]=max({dp[i][0],dp[i-2][2],dp[i-2][3]})+check(s[i-1],t[i-1],t[i]);
            dp[i][1]=max({dp[i][1],dp[i-2][2],dp[i-2][3]})+check(s[i-1],s[i],t[i-1]);
        }
        if(i-1>=0){
            dp[i][2]=max({dp[i][2],dp[i-1][0]})+check(s[i-1],s[i],t[i]);
            dp[i][3]=max({dp[i][3],dp[i-1][1]})+check(s[i],t[i-1],t[i]);
        }
        if(i-3>=0){
            dp[i][0]=max(dp[i][0],dp[i-3][0]+check(s[i-3],s[i-2],s[i-1])+check(t[i-2],t[i-1],t[i]));
            dp[i][1]=max(dp[i][1],dp[i-3][1]+check(s[i-2],s[i-1],s[i])+check(t[i-3],t[i-2],t[i-1]));
            dp[i][2]=max(dp[i][2],max(dp[i-3][2],dp[i-3][3])+check(s[i-2],s[i-1],s[i])+check(t[i-2],t[i-1],t[i]));
            dp[i][3]=max(dp[i][3],max(dp[i-3][2],dp[i-3][3])+check(s[i-2],s[i-1],s[i])+check(t[i-2],t[i-1],t[i]));
        }
    }
    cout<<max(dp[n][2],dp[n][3])<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}