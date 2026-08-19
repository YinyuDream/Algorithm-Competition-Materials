#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int pw3[11];
void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    string s[n+1];
    for(int i=1;i<=n;i++)
        cin>>s[i];
    vector<vector<int>> dp(n+1,vector<int>(pw3[k],0)),can(n+1,vector<int>(pw3[k],0));
    dp[0][0]=can[0][0]=1;
    for(int i=0;i<n;i++){
        string &op=s[i+1];
        for(int j=0;j<pw3[k];j++){
            if(!can[i][j]) continue;
            dp[i+1][j]=(dp[i][j]+dp[i+1][j])%m;
            can[i+1][j]=1;
            int val=0,now=j;
            for(int l=k-1;l>=0;l--){
                int x=now%3;
                if(op[l]=='+'){
                    x=(x+1)%3;
                }
                if(op[l]=='-'){
                    x=(x+2)%3;
                }
                val+=x*pw3[k-l-1];
                now/=3;
            }
            dp[i+1][val]=(dp[i][j]+dp[i+1][val])%m;
            can[i+1][val]=1;
        }
    }
    map<string,int> mp;
    for(int i=0;i<pw3[k];i++){
        if(!can[n][i]) continue;
        string t;
        int val=i;
        for(int j=0;j<k;j++){
            t+=(val%3+'A');
            val/=3;
        }
        reverse(t.begin(),t.end());
        mp[t]=dp[n][i];
    }
    for(auto [x,y]:mp)
        cout<<x<<' '<<y<<endl;
}
int main(){
    pw3[0]=1;
    for(int i=1;i<=10;i++)
        pw3[i]=pw3[i-1]*3;
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}