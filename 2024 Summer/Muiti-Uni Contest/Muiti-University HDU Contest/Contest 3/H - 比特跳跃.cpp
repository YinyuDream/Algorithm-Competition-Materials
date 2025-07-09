#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
void write(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
class Graph{
    private:
        int n;
        struct node{
            int to;
            int next;
            ll wt;
        };
        vector<node> edge;
        vector<int> head;
        int cnt;
    public:
        Graph(int n,int m):n(n){
            edge.resize(m+1);
            head.resize(n+1);
            cnt=0;
        }
        void add_edge(int u,int v,ll w){
            edge[++cnt].to=v;
            edge[cnt].next=head[u];
            edge[cnt].wt=w;
            head[u]=cnt;
        }
        void add_edges(int u,int v,ll w){
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        void dijkstra(int start,vector<ll> &ans){
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
            vector<bool> vis(n+1,false);
            ans.resize(n+1,1e18);
            ans[start]=0;
            q.push(make_pair(0,start));
            while(!q.empty()){
                int u=q.top().second;
                q.pop();
                if(vis[u]) continue;
                vis[u]=true;
                for(int i=head[u];i;i=edge[i].next){
                    int v=edge[i].to;
                    ll w=edge[i].wt;
                    if(ans[v]>ans[u]+w){
                        ans[v]=ans[u]+w;
                        q.push(make_pair(ans[v],v));
                    }
                }
            }
        }      
};
void solve(){
    int n,m;
    ll k;
    n=read(),m=read(),k=read();
    Graph G(n,2*n),H(n,4*n);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        u=read(),v=read(),w=read();
        G.add_edges(u,v,min(w,k*(u|v)));
        H.add_edges(u,v,min(w,k*(u|v)));
    }
    vector<int> g(n+1);
    vector<ll> dij,f(n+1);
    G.dijkstra(1,dij);
    f[1]=dij[1],g[1]=1;
    for(int i=2;i<=n;i++){
        H.add_edge(1,i,k*(1|i));
        f[i]=1e18;
        if(__builtin_popcount(i)==1){
            if(dij[i]<1e18){
                f[i]=dij[i];
                g[i]=i;
            }
            continue;
        }
        int highbit=31-__builtin_clz(i);
        for(int j=0;j<=highbit;j++){
            if(i&(1<<j)){
                int val=i^(1<<j);
                if(f[val]<f[i]&&f[val]<1e18){
                    f[i]=f[val];
                    g[i]=g[val];
                }
                val=i^(1<<highbit);
                if(f[val]<f[i]&&f[val]<1e18){
                    f[i]=f[val];
                    g[i]=g[val];
                }
            } 
        }
        if(f[i]<1e18&&g[i]>1&&f[i]+k*i<dij[i])
            H.add_edge(g[i],i,k*i);
        if(f[i]>dij[i]){
            f[i]=dij[i];
            g[i]=i;
        }
    }
    vector<ll>ans;
    H.dijkstra(1,ans);
    for(int i=2;i<=n;i++)
        write(ans[i]),putchar(' ');
    putchar('\n');
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}