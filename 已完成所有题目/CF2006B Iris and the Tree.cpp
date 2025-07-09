#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n,cnt_edge=0;
    ll w;
    cin>>n>>w;
    vector<int> f(n+1),head(n+1),dep(n+1);
    vector<node> edge(n+1);
    map<pii,vector<int>> mp;
    auto add=[&](int u,int v){
        edge[++cnt_edge].to=v;
        edge[cnt_edge].next=head[u];
        head[u]=cnt_edge;
    };
    for(int i=2;i<=n;i++){
        cin>>f[i];
        add(f[i],i);
    }
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa)
                continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    vector<set<pii>> path(n+1);
    for(int i=1;i<=n;i++){
        int u=i,v=i%n+1;
        if(dep[u]<dep[v])
            swap(u,v);
        while(dep[u]>dep[v]){
            path[i].insert({f[u],u});
            mp[{f[u],u}].push_back(i);
            u=f[u];
        }
        while(u!=v){
            path[i].insert({f[u],u});
            mp[{f[u],u}].push_back(i);
            path[i].insert({f[v],v});
            mp[{f[v],v}].push_back(i);
            u=f[u];
            v=f[v];
        }
    }
    int cnt=n;
    ll ans=w*n,tot=0;
    vector<ll> sum(n+1,0);
    for(int i=1;i<n;i++){
        int pos;
        ll val;
        cin>>pos>>val;
        pii p={f[pos],pos};
        int t1=mp[p][0],t2=mp[p][1];
        ans-=(cnt-2)*val;
        path[t1].erase({f[pos],pos});
        if(path[t1].size()==0){
            cnt--;
            ans-=w-(tot-sum[t1]);
            ans+=sum[t1]+val;
        }
        sum[t1]+=val;
        path[t2].erase({f[pos],pos});
        if(path[t2].size()==0){
            cnt--;
            ans-=w-(tot-sum[t2]);
            ans+=sum[t2]+val;
        }sum[t2]+=val;
        tot+=val;
        cout<<ans<<" \n"[i==n-1];
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