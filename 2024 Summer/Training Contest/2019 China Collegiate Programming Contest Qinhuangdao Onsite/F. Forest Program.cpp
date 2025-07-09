#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
struct node{
    int to,next;
};
int main(){
    int n,m,cnt_edge=1;
    cin>>n>>m;
    vector<int> pw2(n+1);
    pw2[0]=1;
    for(int i=1;i<=n;++i){
        pw2[i]=1ll*pw2[i-1]*2%p;
    }
    vector<node> edge(m*2+2);
    vector<int> head(n+1);
    auto add_edge=[&](int u,int v){
        edge[++cnt_edge].to=v;
        edge[cnt_edge].next=head[u];
        head[u]=cnt_edge;
    };
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    int cnt=0;
    vector<int> dep(n+1),fa(n+1);
    vector<vector<int>> res(n+1);
    auto get=[&](int u,int v){
        if(dep[u]<dep[v])
            return;
        cnt++;
        res[cnt].push_back(v);
        while(u!=v){
            res[cnt].push_back(u);
            u=fa[u];
        }
    };
    function<void(int,int)> dfs=[&](int u,int f){
        fa[u]=f,dep[u]=dep[f]+1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==f)continue;
            if(dep[v])get(u,v);
            else dfs(v,u);
        }
    };
    for(int i=1;i<=n;++i){
        if(!dep[i]){
            dfs(i,0);
        }
    }
    int ans=1,tot=0;
    for(int i=1;i<=cnt;++i){
        ans=1ll*ans*pw2[res[i].size()-1]%p;
        tot+=res[i].size();
    }
    ans=1ll*ans*pw2[m-tot]%p;
    cout<<ans<<endl;
    return 0;
}