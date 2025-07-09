#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
class Graph{
    private:
        struct Edge{
            int to;
            int next;
        };
        vector<Edge> edge;
        vector<int> head;
        vector<int> dep;
        int n,cnt;
    public:
        Graph(int n){
            this->n=n;
            edge.resize(2*n+1);
            head.resize(n+1);
            dep.resize(n+1);
            cnt=0;
        }
        void add_edge(int u,int v){
            edge[++cnt].to=v;
            edge[cnt].next=head[u];
            head[u]=cnt;
        }
        void dfs(int u,int fa){
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                if(v==fa) continue;
                dep[v]=dep[u]+1;
                dfs(v,u);
            }
        }
        int diameter(){
            int st = 0;
            for(int i=1;i<=n;i++){
                if(head[i]){
                    st=i;
                    break;
                }
            }
            dfs(st,0);
            int max_dep=0;
            int max_dep_node=0;
            for(int i=1;i<=n;i++){
                if(dep[i]>=max_dep){
                    max_dep=dep[i];
                    max_dep_node=i;
                }
            }
            dep[max_dep_node]=0;
            dfs(max_dep_node,0);
            int ans=0;
            for(int i=1;i<=n;i++){
                ans=max(ans,dep[i]);
            }
            return ans;
        }
        int get_dep(int u){
            return dep[u];
        }
};
void solve(){
    int n,s,r1,r2;
    n=read();s=read();r1=read();r2=read();
    Graph g(n);
    vector<pair<int,int>> edge;
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        g.add_edge(u,v);
        g.add_edge(v,u);
        edge.push_back({u,v});
    }
    g.dfs(s,0);
    vector<int> now(n+1);
    for(int i=1;i<=n;i++){
        if(g.get_dep(i)<=r2){
            now[i]=1;
        }
    }
    Graph h(n);
    for(auto [u,v]:edge){
        if(now[u]&&now[v]){
            h.add_edge(u,v);
            h.add_edge(v,u);
        }
    }
    int d=h.diameter();
    if(r1*2>=d){
        puts("Kangaroo_Splay");
    }else{
        puts("General_Kangaroo");
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}