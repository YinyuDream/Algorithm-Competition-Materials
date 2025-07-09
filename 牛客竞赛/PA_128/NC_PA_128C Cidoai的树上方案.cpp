#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct node{
    int to,next;
};
int main(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(n+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v){
        edge[++cnt]={v,head[u]};
        head[u]=cnt;
    };
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        add(u,i);
    }
    vector<long long> ans(n+1,1),mul(n+1,1);
    function<void(int)> dfs=[&](int u){
        long long val=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            dfs(v);
            ans[u]*=ans[v];
            ans[u]%=mod;
            val*=mul[v];
            val%=mod;
        }
        mul[u]=ans[u];
        ans[u]+=val;
        ans[u]%=mod;
    };
    dfs(1);
    cout<<ans[1]<<endl;
    return 0;
}