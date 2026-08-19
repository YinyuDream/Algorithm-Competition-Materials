#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> cnt(26,0);
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    string ans;
    while(true){
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                ans.push_back(i+'a');
                cnt[i]--;
                n--;
            }
        }
        if(n==0){
            break;
        }
    }
    cout<<ans<<endl;  
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}