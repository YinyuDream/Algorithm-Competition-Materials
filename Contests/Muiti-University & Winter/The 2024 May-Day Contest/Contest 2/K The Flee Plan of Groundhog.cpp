#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,t,now;
struct node{
    int to,next;
}edge[maxn];
int head[maxn],dis[maxn],st[maxn],top;
void add(int u,int v)
{
    edge[++k]={v,head[u]};
    head[u]=k;
}
void dfs(int u,int f)
{
    st[++top]=u;
    if(u==n){
        if(top>=t+1)
            now=st[t+1];
        else top=n;
    }
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
            dfs(v,u);
        }
    }
    top--;
}
int time_Orange[maxn];
void find_t(int u,int f,int d)
{
    time_Orange[u]=d/2;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
            find_t(v,u,d+1);
        }
    }
}
int ans=0;
void solve(int u,int f,int d)
{
    ans=max(ans,time_Orange[u]);
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f&&time_Orange[v]>d+1){
            solve(v,u,d+1);
        }
    }
}
int main(){
    cin>>n>>t;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    find_t(n,n,1);
    solve(now,now,0);
    cout<<ans;
    return 0;
}