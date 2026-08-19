#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    set<pair<int,int>> st1,st2;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        st1.insert({x,y});
        st1.insert({x+1,y});
        st2.insert({x,y});
        st2.insert({x,y+1});
    }
    cout<<st1.size()+st2.size();
    return 0;
}