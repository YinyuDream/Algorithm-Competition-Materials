#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n;
    ll c;
    cin>>n>>c;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<node> edge(n*2+1);
    vector<int> head(n+1);
    int cnt=0;
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
    vector<array<ll,2>> dp(n+1);
    function<void(int,int)> dfs=[&](int u,int fa){
        dp[u][0]=dp[u][1]=0;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa) continue;
            dfs(v,u);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=max(dp[v][0],dp[v][1]-2*c);
        }
        dp[u][1]+=a[u];
    };
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}