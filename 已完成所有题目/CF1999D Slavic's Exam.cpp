#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size(),now=0;
    for(int i=0;i<n;i++){
        if(s[i]=='?'||s[i]==t[now]){
            s[i]=t[now];
            now++;
        }
        if(now==m)break;
    }
    if(now<m){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++)
        if(s[i]=='?')
            s[i]='a';
    cout<<"YES"<<endl<<s<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}