#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
set<char> st={'n','a','r','e','k'};
vector<char> ch;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=" "+a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(5,-1e9));
    auto work=[&](int pos,int eth){
        int sn=0,sc=0;
        for(int i=1;i<=m;i++){
            if(a[pos][i]==ch[(eth+1)%5]){
                sn++;
                eth=(eth+1)%5;
            }else{
                if(st.count(a[pos][i])){
                    sc++;
                }
            }
        }
        return make_pair(sn-sc,eth);
    };
    for(int i=1;i<=n;i++){ 
        auto _=work(i,4);
        dp[i][_.second]=_.first;
        for(int j=0;j<=4;j++){
            vector<pair<int,int>> can;
            for(int k=0;k<=4;k++){
                auto [score,eth]=work(i,k);
                if(eth==j){
                    can.push_back({score,k});
                }
            }
            for(auto [score,pos]:can){
                for(int k=1;k<i;k++)
                    dp[i][j]=max(dp[i][j],dp[k][pos]+score);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][4]);
    cout<<ans<<endl;    
}
int main(){
    ch.push_back('n');
    ch.push_back('a');
    ch.push_back('r');
    ch.push_back('e');
    ch.push_back('k');
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}