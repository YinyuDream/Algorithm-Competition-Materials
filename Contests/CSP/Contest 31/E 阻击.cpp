#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,k;
struct node{
    int to,next;
    ll w,b;
}edge[maxn];
int head[maxn];
void add(int u,int v,ll w,ll b)
{
    edge[++k]={v,head[u],w,b};
    head[u]=k;
}
void dfs(int u,int f,ll dis,ll &mx,int &mxp)
{
    if(dis>mx){
        mx=dis;
        mxp=u;
    }
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
            if(dis+edge[i].b-edge[i].w>=0)dfs(v,u,dis+edge[i].b-edge[i].w,mx,mxp);
            else dfs(v,u,0,mx,mxp);
        }
    }
}
ll work()
{
    ll mx=-1e18;
    int mxp=0;
    dfs(1,1,0,mx,mxp);
    mx=-1e18;
    dfs(mxp,mxp,0,mx,mxp);
    return mx>=0?mx:0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;
        ll w,b;
        cin>>u>>v>>w>>b;
        add(u,v,w,b);
        add(v,u,w,b);
    }
    cout<<work()<<endl;
    for(int i=1;i<=m;i++){
        int x;
        ll y;
        cin>>x>>y;
        edge[x*2-1].w=edge[x*2].w=y;
        cout<<work()<<endl;
    }
    return 0;
}