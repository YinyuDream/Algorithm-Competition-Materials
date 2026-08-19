#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
    ll wt;
};
int main(){
    int n,m,cnt=0;
    cin>>n>>m;
    vector<node> edge(2*m+1);
    vector<int> head(n+1);
    auto add_edge=[&](int u,int v,ll w){
        edge[++cnt].to=v;
        edge[cnt].wt=w;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    vector<int> book(n+1),in(n+1);
    vector<ll> ans(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,-w);
        in[v]++;
    }
    function<void(int)> dfs=[&](int u){
        book[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            ll w=edge[i].wt;
            if(book[v]==0){
                ans[v]=ans[u]+w;
                dfs(v);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(book[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}