#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next;
};
int main(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1,0),fac(n+1);
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
        fac[i]=fac[i-1]*i;
    }
    vector<int> dp(n+1),fa(n+1),sz(n+1);
    function<void(int,int)> dfs=[&](int u,int f){
        int tot=0;
        dp[u]=1;
        sz[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==f) continue;
            fa[v]=u;
            dfs(v,u);
            dp[u]*=dp[v];
            sz[u]+=sz[v];
            tot++;
        }
        dp[u]*=fac[tot];
    };
    dfs(1,0);
    vector<vector<int>> g(n+1,vector<int>(n+1));//root as fa_x, subtree x in y-th dfs order
    for(int i=1;i<=n;i++){
        vector<int> son;
        vector<pair<int,int>> val;
        son.push_back(0);
        val.push_back({0,0});
        for(int j=head[i];j;j=edge[j].next){
            int v=edge[j].to;
            if(v==fa[i]) continue;
            son.push_back(v);
            val.push_back({sz[v],dp[v]});
        }
        vector<vector<vector<int>>> tmp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
        //前i个儿子，选j个，和为k的方案数
        tmp[0][0][0]=1;
        int tot_son=son.size()-1;
        for(int j=1;j<=tot_son;j++){
            for(int k=0;k<=tot_son;k++){
                for(int l=0;l<sz[i];l++){
                    tmp[j][k][l]=tmp[j-1][k][l];
                    if(k>=1&&l>=val[j].first) tmp[j][k][l]+=tmp[j-1][k-1][l-val[j].first]*val[j].second;
                }
            }
        }
    }
    return 0;
}