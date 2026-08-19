#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,cnt;
struct node{
    int to,nxt;
}edge[maxn];
int head[maxn],u[maxn],v[maxn],q[maxn],dep[maxn],fa[maxn],sz[maxn],in[maxn];
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(y==fa) continue;
        dfs(y,x);
    }
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fy]=fx,sz[fx]=max(sz[fx],sz[fy]+dep[x]-dep[fx]+1);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        head[i]=u[i]=v[i]=q[i]=dep[i]=fa[i]=sz[i]=edge[i].to=edge[i].nxt=in[i]=0;
    cnt=0;
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i]>>q[i];
        add(u[i],v[i]);
        in[v[i]]++;
    }
    int root=0;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            root=i;
            break;
        }
    }
    dfs(root,0);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<n;i++){
        merge(u[i],v[i]);
        cout<<sz[find(q[i])]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}