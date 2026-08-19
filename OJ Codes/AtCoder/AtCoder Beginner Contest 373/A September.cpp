#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=12,ans=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(i==s.size()){
            ans++;
        }
    }
    cout<<ans;
}