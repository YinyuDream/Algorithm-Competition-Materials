#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k;
struct node{
    int to,next;
}edge[maxn];
int head[maxn];
int dep[maxn];
ll ans,sum[maxn],c[maxn];
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void dfs1(int u,int f)
{
    ans+=dep[u]*c[u];
    sum[u]=c[u];
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
            dep[v]=dep[u]+1;
            dfs1(v,u);
            sum[u]+=sum[v];
        }
    }
}
void dfs2(int u,int f,ll num)
{
    ans=max(ans,num);
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
            dfs2(v,u,num-sum[v]+(sum[1]-sum[v]));
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs1(1,1);
    dfs2(1,1,ans);
    cout<<ans<<endl;
    return 0;
}