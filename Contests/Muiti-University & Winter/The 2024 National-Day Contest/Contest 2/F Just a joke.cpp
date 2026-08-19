#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> fa(n+1);
    iota(fa.begin(),fa.end(),0);
    function<int(int)> find=[&](int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    };
    int cnt=n,tot=0;
    auto merge=[&](int u,int v){
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
            cnt--;
        }else{
            tot++;
        }
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    cout<<(((cnt+tot)&1)?"Alice":"Bob");
    return 0;
}