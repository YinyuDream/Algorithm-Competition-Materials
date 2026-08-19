#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,p=998244353;
int T,n;
struct node{
    int to,next;
}edge[maxn];
int head[maxn],cnt;
int f[maxn],g[maxn];
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void work(int u,int fa)
{
    if(head[u]==0){
        f[u]=1,g[u]=0;
        return ;
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        work(v,u);
        cnt++;
    }
    f[u]=1,g[u]=0;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa) continue;
        f[u]=1ll*f[u]*(f[v]+1)%p;
        g[u]=(g[u]+(f[v]+g[v])%p)%p;
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        work(1,1);
        cout<<(f[1]+g[1]+1)%p<<endl;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<=cnt;i++)
            edge[i].to=edge[i].next=0;
        cnt=0;
        for(int i=1;i<=n;i++)
            f[i]=g[i]=0;
    }
    return 0;
}