#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string a="ava",b="avava";
    string s;
    cin>>s;
    int n=s.size(),pos=0;
    while(pos<n){
        if(s.substr(pos,5)==b){
            pos+=5;
        }
        else if(s.substr(pos,3)==a){
            pos+=3;
        }else{
            cout<<"No"<<endl;
            return;
        }
    }
    if(pos==n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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