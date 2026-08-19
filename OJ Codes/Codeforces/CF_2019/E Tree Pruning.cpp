#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,nxt;
};
void solve(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1);
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].nxt=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    vector<int> dep(n+1),book(n+1),f(n+1);
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(v==fa){
                continue;
            }
            f[v]=u;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
    };
    dep[1]=1;
    dfs(1,0);
    int mx=*max_element(dep.begin(),dep.end());
    vector<vector<int>> p(n+2);
    for(int i=1;i<=n;i++){
        p[dep[i]].push_back(i);
    }
    int tot=0,ans=n+1;
    for(int i=mx;i>=1;i--){
        for(auto x:p[i+1]){
            book[x]=0;
            tot--;
        }
        for(auto x:p[i]){
            while(x&&!book[x]){
                book[x]=1;
                x=f[x];
                tot++;
            }
        }
        ans=min(ans,n-tot);
    }
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