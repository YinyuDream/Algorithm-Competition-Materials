#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> c(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    vector<int> fa(n);
    iota(fa.begin(),fa.end(),0);
    auto find=[&](auto &&self,int x)->int{
        return x==fa[x]?x:fa[x]=self(self,fa[x]);
    };
    auto merge=[&](int u,int v){
        int fu=find(find,u),fv=find(find,v);
        if(fu!=fv){
            fa[fu]=fv;
        }
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        merge(u-1,v-1);
    }
    map<int,map<int,int>> num;
    for(int i=0;i<n;i++){
        int f=find(find,i);
        num[f][c[i]]++;
    }
    int ans=0;
    for(auto &[block,all]:num){
        int tot=0,mx=0;
        for(auto &[col,num]:all){
            tot+=num;
            mx=max(mx,num);
        }
        ans+=tot-mx;
    }
    cout<<ans;
    return 0;
}