#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(mp.find(v)==mp.end())
            mp.insert(make_pair(v,u));
        else mp[v]=min(mp[v],u);
    }
    int ans=0;
    for(auto i:mp){
        ans=max(ans,i.second);
    }
    cout<<ans;
}