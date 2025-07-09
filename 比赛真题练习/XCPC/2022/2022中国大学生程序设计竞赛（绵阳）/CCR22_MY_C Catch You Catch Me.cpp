#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans,k;
struct node{
    int to,next;
}edge[maxn*2];
int head[maxn],dep[maxn],mx_dep[maxn];
void add(int u,int v)
{
    edge[++k]={v,head[u]};
    head[u]=k;
}
void dfs(int u,int f)
{
    mx_dep[u]=dep[u];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==f) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        mx_dep[u]=max(mx_dep[u],mx_dep[v]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    for(int i=head[1];i;i=edge[i].next){
        int v=edge[i].to;
        ans+=mx_dep[v];
    }
    cout<<ans<<endl;
    return 0;
}