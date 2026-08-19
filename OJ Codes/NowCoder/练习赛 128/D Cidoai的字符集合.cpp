#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    map<string,int> mp;
    vector<vector<int>> bel(1e6+1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            string s;
            cin>>s;
            if(mp.find(s)==mp.end()){
                mp[s]=++cnt;
            }
            bel[mp[s]].push_back(i);
        }
    }
    vector<int> fa(n+1);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    function<int(int)> find=[&](int u){
        return u==fa[u]?u:fa[u]=find(fa[u]);
    };
    auto merge=[&](int u,int v){
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
        }
    };
    for(int i=1;i<=cnt;i++){
        if(bel[i].size()>1){
            int sz=bel[i].size();
            for(int j=0;j<sz-1;j++){
                merge(bel[i][j],bel[i][j+1]);
            }
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++){
        st.insert(find(i));
    }
    cout<<st.size();
    return 0;
}