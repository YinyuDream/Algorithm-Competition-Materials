#include<bits/stdc++.h>
using namespace std;
int n,q;
set<int> s;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(s.find(t)!=s.end()) s.erase(t);
        else s.insert(t);
    }
    cout<<s.size();
    return 0;
}