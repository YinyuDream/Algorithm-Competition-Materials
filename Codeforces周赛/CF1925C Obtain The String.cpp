#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<vector<int>> pos(26);
    vector<vector<int>> nxt(n,vector<int>(26));
    for(int i=0;i<n;i++){
        pos[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<n;i++){
        char c=s[i];
        for(int j=0;j<26;j++){
            if(pos[j].size()==0){
                nxt[i][j]=-1;
            }else{
                auto it=upper_bound(pos[j].begin(),pos[j].end(),i);
                if(it==pos[j].end()){
                    nxt[i][j]=pos[j][0];
                }else{
                    nxt[i][j]=*it;
                }
            }
        }
    }
    int m=t.size();
    for(int i=0;i<m;i++){
        if(pos[t[i]-'a'].size()==0){
            cout<<-1<<endl;
            return;
        }
    }
    int ans=1,now=pos[t[0]-'a'][0];
    for(int i=1;i<m;i++){
        char c=t[i];
        if(nxt[now][c-'a']<=now){
            ans++;
        }
        now=nxt[now][c-'a'];
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