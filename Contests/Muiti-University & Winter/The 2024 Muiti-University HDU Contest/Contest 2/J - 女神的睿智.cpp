#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s;
    cin>>s;
    if(s[0]==s[4]){
        cout<<s[0]<<endl;
    }else{
        int cnt_0=0,cnt_1=0;
        for(int i=0;i<8;i++){
            if(s[i]==s[0]) cnt_0++;
            if(s[i]==s[4]) cnt_1++;
        }
        if(cnt_0>cnt_1){
            cout<<s[0]<<endl;
        }else if(cnt_0<cnt_1){
            cout<<s[4]<<endl;
        }else{
            cout<<"N"<<endl;
        }
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