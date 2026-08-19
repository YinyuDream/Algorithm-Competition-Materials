#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(n%2!=0){
        cout<<"No"<<endl;
        return 0;
    }
    s=" "+s;
    map<char,int> mp;
    for(int i=1;i<=n;i+=2){
        if(s[i]!=s[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
        mp[s[i]]++;
    }
    for(auto [x,y]:mp){
        if(y>1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}