#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),fa(n+1),sz(n+1,1),book(n+1,0);
    function<int(int)> find=[&](int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    };
    function<void(int,int)> merge=[&](int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        fa[y]=x;
        sz[x]+=sz[y];
    };
    
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        merge(i,a[i]);
    }
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        int u=find(i);
        if(book[u]==0){
            if(sz[u]%3!=2){
                ans+=(sz[u]+1)/3;
            }else{
                ans+=(sz[u]+1)/3-1;
                cnt++;
            }
            book[u]=1;
        }
    }
    
    cout<<ans+(cnt+1)/2<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}