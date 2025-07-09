#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,cnt;
int in[maxn],t[maxn];
set<int> G[maxn];
priority_queue<pair<int,int>> q;
int main(){
    cin>>n;
    cnt=n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
        in[u]++;
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        t[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==1){
            q.push({-t[i],i});
        }
    }
    while(q.size()){
        auto [d,u]=q.top();
        q.pop();
        d=-d;
        if(G[u].begin()==G[u].end())
            continue;
        int nxt=*G[u].begin();
        if(t[u]<=t[nxt]){
            cnt--;
            t[nxt]+=t[u];
            in[nxt]--;
            G[nxt].erase(u);
            G[u].erase(nxt);
            if(in[nxt]==1){
                q.push({-t[nxt],nxt});
            }
        }
    }
    if(cnt==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}