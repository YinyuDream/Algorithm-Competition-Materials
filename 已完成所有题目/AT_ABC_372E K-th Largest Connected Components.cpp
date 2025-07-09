#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<set<int>> g(n+1);
    vector<int> fa(n+1),sz(n+1);
    function<int(int)> find=[&](int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    };
    auto merge=[&](int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            if(sz[x]>sz[y]) swap(x,y);
            fa[x]=y;
            sz[y]+=sz[x];
            for(auto i:g[x]){
                g[y].insert(i);
            }
            g[x].clear();
            while(g[y].size()>10){
                g[y].erase(g[y].begin());
            }
        }
    };
    for(int i=1;i<=n;i++){
        fa[i]=i;
        g[i].insert(i);
        sz[i]=1;
    }
    for(int i=1;i<=q;i++){
        int op,u,v;
        cin>>op>>u>>v;
        if(op==1){
            merge(u,v);
        }else{
            int x=find(u);
            if(g[x].size()<v){
                cout<<-1<<endl;
            }else{
                auto it=g[x].end();
                while(v--){
                    it--;
                }
                cout<<*it<<endl;
            }
        }
    }
}