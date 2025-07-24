#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<pair<int,int>> s;
    for(int i=1;i<=n+1;i++){
        s.insert({i,i});
        s.insert({i-1,i});
        s.insert({i,i-1});
        s.insert({i-1,i-1});
    }
    cout<<s.size()<<endl;
    for(auto it:s){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}