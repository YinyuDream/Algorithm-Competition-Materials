#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    struct node{
        int to,next;
        node(int to=0,int next=0):to(to),next(next){};
    };
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<node> edge(n*2+1,0);
    vector<int> head(n+1,0);
    int tot=0;
    auto add=[&](int u,int v){
        edge[++tot].to=v;
        edge[tot].next=head[u];
        head[u]=tot;
    };
    
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    int lim=max(3.0,log2(n)+1);
    vector<vector<ll>> dp(n+1,vector<ll>(lim,0));
    function<void(int, int)> dfs;
    dfs=[&](int u,int f){
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v!=f){
                dfs(v,u);
                for(int j=0;j<lim;j++){
                    ll minn=1e18;
                    for(int k=0;k<lim;k++){
                        if(k!=j){
                            minn=min(minn,dp[v][k]);
                        }
                    }
                    dp[u][j]+=minn;
                }
            }
        }
        for(int i=0;i<lim;i++)
            dp[u][i]+=a[u]*(i+1);
    };
    int root=rand()%n+1;
    dfs(root,0);
    ll ans=1e18;
    for(int i=0;i<lim;i++)
        ans=min(ans,dp[root][i]);
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