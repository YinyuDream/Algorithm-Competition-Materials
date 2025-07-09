#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
void solve(){
    string s;
    cin>>s;
    map<char,vector<string>> mp;

    mp['Y'].push_back("QQQ");
    mp['Y'].push_back("QQQ");
    mp['Y'].push_back("QQQ");
    mp['Y'].push_back("QQQ");
    mp['Y'].push_back("QQQ");
    mp['Y'].push_back("QQQ");

    mp['V'].push_back("OQW");
    mp['V'].push_back("OQQ");
    mp['V'].push_back("OQW");
    mp['V'].push_back("OQQ");
    mp['V'].push_back("OQW");
    mp['V'].push_back("OQQ");

    mp['G'].push_back("QEE");
    mp['G'].push_back("QEQ");
    mp['G'].push_back("EQO");
    mp['G'].push_back("QEE");
    mp['G'].push_back("QEQ");
    mp['G'].push_back("EQO");

    mp['C'].push_back("WMW");
    mp['C'].push_back("WMW");
    mp['C'].push_back("WMW");
    mp['C'].push_back("WMW");
    mp['C'].push_back("WMW");
    mp['C'].push_back("WMW");

    mp['X'].push_back("QWW");
    mp['X'].push_back("WQW");
    mp['X'].push_back("WWQ");
    mp['X'].push_back("QWW");
    mp['X'].push_back("WQW");
    mp['X'].push_back("WWQ");

    mp['Z'].push_back("WWE");
    mp['Z'].push_back("WEW");
    mp['Z'].push_back("EWW");
    mp['Z'].push_back("WWE");
    mp['Z'].push_back("WEW");
    mp['Z'].push_back("EWW");

    mp['T'].push_back("EEE");
    mp['T'].push_back("EEE");
    mp['T'].push_back("EEE");
    mp['T'].push_back("EEE");
    mp['T'].push_back("EEE");
    mp['T'].push_back("EEE");

    mp['F'].push_back("QEE");
    mp['F'].push_back("QEQ");
    mp['F'].push_back("EQO");
    mp['F'].push_back("QEE");
    mp['F'].push_back("QEQ");
    mp['F'].push_back("EQO");

    mp['D'].push_back("WEE");
    mp['D'].push_back("EWE");
    mp['D'].push_back("EEW");
    mp['D'].push_back("WEE");
    mp['D'].push_back("EWE");
    mp['D'].push_back("EEW");

    mp['B'].push_back("QWE");
    mp['B'].push_back("QEW");
    mp['B'].push_back("WQE");
    mp['B'].push_back("WEQ");
    mp['B'].push_back("EQW");
    mp['B'].push_back("EWQ");

    vector<int> dp(s.size()+1);
    for(int i=1;i<=s.size();++i){
        dp[i].resize(6);
        if(i==1)continue;
        for(int j=0;j<6;++j){
            dp[i][j]=1e9;
            for(int k=0;k<6;++k){
                string t=mp[s[i-2]][k];
                string tar=mp[s[i-1]][j];
                int now;
                ll f=1;
                for(int x=0;x<3;x++){
                    if(t[x]!=tar[x]){
                        f=0;
                    }
                }
                if(f){
                    now=0;
                } else {
                    f=1;
                    for(int x=1;x<3;x++){
                        if(t[x]!=tar[x-1]){
                            f=0;
                        }
                    }
                    if(f){
                        now=1;
                    } else {
                        f=1;
                        if(t[2]!=tar[0]){
                            f=0;
                        }
                        if(f){
                            now=2;
                        } else {
                            now=3;
                        }
                    }
                }
                dp[i][j]=min(dp[i][j],dp[i-1][k]+now);
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<6;++i){
        ans=min(dp[s.size()][i],ans);
    }
    cout<<ans+s.size()*3<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    while(t--){
        solve();
    }
}