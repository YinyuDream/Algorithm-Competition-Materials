#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> G(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    vector<tuple<int,int,int>> ans;
    for(int i=1;i<=n;i++){
        while(G[i].size()>1){
            int p=*G[i].begin();
            G[i].erase(p);
            G[p].erase(i);
            int q=*G[i].begin();
            G[i].erase(q);
            G[q].erase(i);
            ans.push_back({i,p,q});
            if(G[p].find(q)==G[p].end()){
                G[p].insert(q);
                G[q].insert(p);
            }else{
                G[p].erase(q);
                G[q].erase(p);
            }
        }
    }
    vector<int> single;
    vector<pair<int,int>> edge;
    for(int i=1;i<=n;i++){
        if(G[i].empty()){
            single.push_back(i);
        }else{
            if(*G[i].begin()>i){
                edge.push_back({i,*G[i].begin()});
            }
        }
    }
    if(single.size()==n){
        cout<<ans.size()<<endl;
        for(auto [a,b,c]:ans){
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return ;
    }
    int root=edge[0].first,now=edge[0].second;
    for(auto [a,b]:edge){
        if(a==root){
            continue;
        }
        ans.push_back({a,b,root});
    }
    for(auto x:single){
        ans.push_back({x,root,now});
        now=x;
    }
    cout<<ans.size()<<endl;
    for(auto [a,b,c]:ans){
        cout<<a<<" "<<b<<" "<<c<<endl;
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