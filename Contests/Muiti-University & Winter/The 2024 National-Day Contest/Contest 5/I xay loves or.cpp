#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,s;
    cin>>x>>s;
    long long ans=1;
    for(int i=0;i<=31;i++){
        int u=(x>>i)&1,v=(s>>i)&1;
        if(u==1){
            if(v==0){
                ans=0;
            }else{
                ans*=2;
            }
        }
    }
    if(0|x==s){
        ans--;
    }
    cout<<ans;
    return 0;
}