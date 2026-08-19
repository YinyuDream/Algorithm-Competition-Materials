#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        auto new_end=std::unique(s.begin(),s.end());
        s.erase(new_end,s.end());
        if(s==t){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}