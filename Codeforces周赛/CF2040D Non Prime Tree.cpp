#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int prime[maxn],not_prime[maxn],tot;
struct node{
    int to,nex;
};
void init(){
    not_prime[1]=1;
    for(int i=2;i<maxn;i++){
        if(!not_prime[i]){
            prime[tot++]=i;
        }
        for(int j=0;j<tot&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1,-1),ans(n+1);
    set<int> s;
    for(int i=2;i<=n*2;i++){
        s.insert(i);
    }
    ans[1]=1;
    int cnt=0;
    auto add=[&](int u,int v){
        edge[cnt].to=v;
        edge[cnt].nex=head[u];
        head[u]=cnt++;
    };
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int i=head[u];~i;i=edge[i].nex){
            int v=edge[i].to;
            if(v==fa) continue;
            for(auto x:s){
                if(not_prime[abs(x-ans[u])]){
                    ans[v]=x;
                    s.erase(x);
                    break;
                }
            }
        }
        for(int i=head[u];~i;i=edge[i].nex){
            int v=edge[i].to;
            if(v==fa) continue;
            dfs(v,u);
        }
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}