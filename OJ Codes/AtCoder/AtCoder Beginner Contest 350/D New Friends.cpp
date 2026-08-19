#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
int fa[maxn],sz[maxn],tot[maxn],book[maxn];
ll ans;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        int x=find(a),y=find(b);
        if(x!=y){
            fa[x]=y;
            sz[y]+=sz[x];
            tot[y]+=tot[x]+1;
        }else{
            tot[x]++;
        }
    }
    for(int i=1;i<=n;i++){
        int x=find(i);
        if(book[x]==0){
            book[x]=1;
            ans+=1ll*sz[x]*(sz[x]-1)/2-tot[x];
        }
    }
    cout<<ans<<endl;
    return 0;
}