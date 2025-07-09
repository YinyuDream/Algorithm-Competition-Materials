#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),ord(n+1),in(n+1);
    vector<vector<int>> G(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin()+1,ord.end(),[&](int i,int j){
        return a[i]>a[j];
    });
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    if(n==1){
        cout<<a[1]<<endl;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(in[ord[i]]>1){
            vector<int> val;
            for(auto x:G[ord[i]]){
                val.push_back(a[x]);
            }
            sort(val.begin(),val.end(),greater<int>());
            ans=max(ans,max(a[ord[i]],min(val[0],val[1])));
        }
    }
    cout<<ans<<endl;
    return 0;
}