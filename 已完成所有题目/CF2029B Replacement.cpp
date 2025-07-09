#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt_0=0,cnt_1=0;
    for(int i=0;i<n;i++){
        cnt_0+=s[i]=='0';
        cnt_1+=s[i]=='1';
    }
    if(cnt_0==0||cnt_1==0){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n-1;i++){
        if(t[i]=='0'){
            cnt_1--;
        }else{
            cnt_0--;
        }
        if(cnt_0<0||cnt_1<0||((cnt_0==0||cnt_1==0)&&cnt_0+cnt_1>1)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}