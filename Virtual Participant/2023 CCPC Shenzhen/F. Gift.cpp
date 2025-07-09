#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to,next;
};
int main(){
    int n;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1),deg(n+1),cnt(n+1);
    auto add_edge=[&](int u,int v){
        static int tot=0;
        edge[++tot]={v,head[u]};
        head[u]=tot;
    };
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
        deg[u]++;
        deg[v]++;
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        cnt[deg[i]]++;
    }
    for(int i=5;i<=n;i++){
        tot+=cnt[i];
    }
    vector<int> in_stk(n+1),cycle;
    stack<int> stk;
    function<bool(int,int)> dfs=[&](int u,int fa){
        stk.push(u);
        in_stk[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa){
                continue;
            }
            if(in_stk[v]){
                while(stk.top()!=v){
                    cycle.push_back(stk.top());
                    stk.pop();
                }
                cycle.push_back(v);
                return true;
                
            }
            if(dfs(v,u)){
                return true;
            }
        }
        stk.pop();
        in_stk[u]=0;
        return false;
    };
    dfs(1,1);
    cycle.push_back(cycle[0]);
    ll ans=0;
    for(int i=0;i<cycle.size()-1;i++){
        cnt[deg[cycle[i]]]--;
        if(deg[cycle[i]]==5){
            tot--;
        }
        deg[cycle[i]]--;
        cnt[deg[cycle[i]]]++;
        cnt[deg[cycle[i+1]]]--;
        if(deg[cycle[i+1]]==5){
            tot--;
        }
        deg[cycle[i+1]]--;
        cnt[deg[cycle[i+1]]]++;
        if(tot==0){
            ans+=cnt[1]+cnt[2]+cnt[3];
        }
        cnt[deg[cycle[i]]]--;
        deg[cycle[i]]++;
        cnt[deg[cycle[i]]]++;
        if(deg[cycle[i]]==5){
            tot++;
        }
        cnt[deg[cycle[i+1]]]--;
        deg[cycle[i+1]]++;
        cnt[deg[cycle[i+1]]]++;
        if(deg[cycle[i+1]]==5){
            tot++;
        }
    }
    cout<<ans<<endl;
    return 0;
}