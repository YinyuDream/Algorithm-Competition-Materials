#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll val;
    int pos;
    size_t size;
};
bool operator<(node a,node b){
    if(a.val<=0||b.val<=0){
        return a.val>b.val;
    }else{
        if(a.size!=b.size){
            return a.size>b.size;
        }
        return a.val>b.val;
    }
}
void solve(){
    int n;
    cin>>n;
    ll sum=0;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<int> in(n+1);
    vector<set<int>> G(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    ll ans=sum;
    priority_queue<node> q;
    for(int i=1;i<=n;i++){
        if(G[i].size()<=2){
            q.push({a[i],i,G[i].size()});
        }
    }
    while(q.size()){
        auto [val,u,sz]=q.top();
        q.pop();
        if(G[u].empty()||in[u]){
            continue;
        }
        in[u]=1;
        sum-=val;
        ans=max(ans,sum);
        if(G[u].size()==1){
            int v=*G[u].begin();
            G[u].clear();
            G[v].erase(u);
            if(G[v].size()&&G[v].size()<=2){
                if(val>0&&a[v]>0){
                    sum+=val;
                    a[v]+=val;
                }
                q.push({a[v],v,G[v].size()});
            }
        }else{
            int v1=*G[u].begin(),v2=*G[u].rbegin();
            G[u].clear();
            G[v1].erase(u);
            G[v2].erase(u);
            G[v1].insert(v2);
            G[v2].insert(v1);
            if(G[v1].size()&&G[v1].size()<=2){
                q.push({a[v1],v1,G[v1].size()});
            }
            if(G[v2].size()&&G[v2].size()<=2){
                q.push({a[v2],v2,G[v2].size()});
            }
        }
    }
    cout<<max(0ll,ans)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}