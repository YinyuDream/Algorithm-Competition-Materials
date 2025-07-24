#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> cnt(26);
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    vector<int> v;
    for(int i=0;i<26;i++){
        if(cnt[i]>0){
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end(),[&](int a,int b){
        return cnt[a]>cnt[b];
    });
    int pos_mn=-1,pos_mx=-1;
    for(int i=0;i<n;i++){
        if(s[i]-'a'==v.back()){
            pos_mn=i;
        }
        if(s[i]-'a'==v.front()){
            pos_mx=i;
        }
    }
    s[pos_mn]=s[pos_mx];
    cout<<s<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}