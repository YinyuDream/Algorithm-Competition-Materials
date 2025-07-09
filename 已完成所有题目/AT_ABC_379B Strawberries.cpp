#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='O'){
            now++;
            if(now>=k){
                ans++;
                now=0;
            }
        }else{
            now=0;
        }
    }
    cout<<ans;
    return 0;
}