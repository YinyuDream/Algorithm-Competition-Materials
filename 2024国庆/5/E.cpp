#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1),dep(n+1);
    vector<vector<int>> fa(n+1,vector<int>(20));
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    function<void(int,int)> init=[&](int u,int f){
        fa[u][0]=f;
        for(int i=1;i<20;i++){
            fa[u][i]=fa[fa[u][i-1]][i-1];
        }
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==f) continue;
            dep[v]=dep[u]+1;
            init(v,u);
        }
    };
    dep[1]=1;
    init(1,0);
    auto is_ancestor=[&](int u,int v){
        int delta=dep[u]-dep[v];
        for(int i=0;i<20;i++){
            if(delta&(1<<i)) u=fa[u][i];
        }
        return u==v;
    };
    vector<int> ban(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(dep[u]<dep[v]) swap(u,v);
        if(is_ancestor(u,v)){
            ban[u]=v;
        }
    }
    int ans=0;
    function<void(int,int,int)> dfs=[&](int u,int f,int mx){
        mx=max(mx,ban[u]);
        ans=max(ans,dep[u]-mx);
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==f) continue;
            dfs(v,u,mx);
        }
    };
    dfs(1,0,0); 
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}