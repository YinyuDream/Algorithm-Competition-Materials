#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void solve(){
    int n,q,cnt=0;
    cin>>n>>q;
    vector<int> a(n+1),pos(n+1),fa(n+1),sz(n+1);
    vector<int> child[n+1];
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        child[fa[i]].push_back(i);
    }
    function<void(int)> dfs=[&](int u){
        sz[u]=1;
        for(auto v:child[u]){
            dfs(v);
            sz[u]+=sz[v];
        }
    };
    dfs(1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    auto count=[&](int x){
        if(sz[x]==1)
            return 0;
        int tot=0;
        for(int i=pos[x]+1;i<min(pos[x]+sz[x],n+1);i++){
            if(fa[a[i]]==x){
                tot++;
                i+=sz[a[i]]-1;
            }
        }
        return tot;
    };
    for(int i=1;i<=n;i++)
        cnt+=count(a[i]);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        set<int> st;
        if(sz[a[x]]>1)
            st.insert(a[x]);
        if(fa[a[x]])
            st.insert(fa[a[x]]);
        if(sz[a[y]]>1)
            st.insert(a[y]);
        if(fa[a[y]])
            st.insert(fa[a[y]]);
        for(auto v:st)
            cnt-=count(v);
        swap(pos[a[x]],pos[a[y]]);
        swap(a[x],a[y]);
        for(auto v:st)
            cnt+=count(v);
        if(cnt==n-1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}