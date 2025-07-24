#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    map<int,char> forword;
    map<char,int> backword;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        forword.clear();
        backword.clear();
        if(s.size()!=n){
            cout<<"NO"<<endl;
            continue;
        }
        bool can=true;
        for(int j=0;j<n;j++){
            if(forword.find(a[j])==forword.end()){
                forword[a[j]]=s[j];
            }else{
                if(forword[a[j]]!=s[j]){
                    cout<<"NO"<<endl;
                    can=false;
                    break;
                }
            }
            if(backword.find(s[j])==backword.end()){
                backword[s[j]]=a[j];
            }else{
                if(backword[s[j]]!=a[j]){
                    cout<<"NO"<<endl;
                    can=false;
                    break;
                }
            }
        }
        if(can)
            cout<<"YES"<<endl;
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