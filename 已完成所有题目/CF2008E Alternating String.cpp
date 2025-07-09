#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    vector<vector<int>> odd_sum(n+1,vector<int>(26));
    vector<vector<int>> even_sum(n+1,vector<int>(26));
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            odd_sum[i][j]=odd_sum[i-1][j];
            even_sum[i][j]=even_sum[i-1][j];
        }
        if(i%2==0){
            even_sum[i][s[i]-'a']++;
        }else{
            odd_sum[i][s[i]-'a']++;
        }
    }
    if(n%2==0){
        int cnt_1=0,cnt_2=0;
        for(int i=0;i<26;i++){
            cnt_1=max(cnt_1,even_sum[n][i]);
            cnt_2=max(cnt_2,odd_sum[n][i]);
        }
        cout<<n/2-cnt_1+n/2-cnt_2<<endl;
    }else{
        int ans=1e9;
        for(int i=1;i<=n;i++){
            int cnt_1=0,cnt_2=0;
            for(int j=0;j<26;j++){
                cnt_1=max(cnt_1,even_sum[i-1][j]+odd_sum[n][j]-odd_sum[i][j]);
                cnt_2=max(cnt_2,odd_sum[i-1][j]+even_sum[n][j]-even_sum[i][j]);
            }
            ans=min(ans,n/2-cnt_1+n/2-cnt_2+1);
        }
        cout<<ans<<endl;
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