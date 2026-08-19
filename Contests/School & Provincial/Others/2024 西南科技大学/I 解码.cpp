#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]=((s[i]-'a')-k+26)%26+'a';
        }else{
            s[i]=((s[i]-'A')-k+26)%26+'A';
        }
    }
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