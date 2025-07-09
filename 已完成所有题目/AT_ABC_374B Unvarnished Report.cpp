#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    if(s==t){
        cout<<0;
        return 0;
    }
    int n=min(s.size(),t.size());
    int ans=n+1;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            ans=i+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}