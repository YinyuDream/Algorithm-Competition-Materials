#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            cout<<"shameimaru"<<endl;
            return ;
        }
    }
    auto check=[&](int pos){
        vector<int> cnt(26);
        for(int i=1;i<=pos;i++){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']>1){
                return false;
            }
        }
        if((n-pos)%2!=0)return false;
        int len=(n-pos)/2;
        string u=s.substr(pos+1,len);
        string v=s.substr(pos+len+1,len);
        return u==v;
    };
    for(int i=1;i<=min(26,n-1);i++){
        if(check(i)){
            cout<<"aya"<<endl;
            return ;
        }
    }
    cout<<"shameimaru"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}