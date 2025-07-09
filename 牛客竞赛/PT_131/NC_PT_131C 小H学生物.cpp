#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next;
};
string operator^(string u,string v){
    string ans;
    int sz=u.size();
    for(int i=0;i<sz;i++){
        ans.push_back(u[i]==v[i]?'0':'1');
    }
    return ans;
}
int main(){
    int n,m,L;
    cin>>n>>m>>L;
    vector<node> edge(n+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v){
        static int cnt=0;
        edge[++cnt]={v,head[u]};
        head[u]=cnt;
    };
    vector<string> a(n+1),sum(n+1);
    sum[1]=string(L,'0');
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        cin>>a[v];
    }
    vector<int> bk(n+1),c(m+1);
    for(int i=1;i<=m;i++){
        cin>>c[i];
        bk[c[i]]=1;
    }
    function<void(int)> dfs=[&](int u){
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            sum[v]=sum[u]^a[v];
            dfs(v);
        }
    };
    dfs(1);
    string ans=sum[1];
    if(m%2==0){
        for(int i=1;i<=n;i++){
            if(bk[i]){
                ans=ans^sum[i];
            }
        }
    }
    for(int i=1;i<m;i++){
        ans=ans^sum[c[i]];
        ans=ans^sum[c[i+1]];
    }
    cout<<ans;
    return 0;
}