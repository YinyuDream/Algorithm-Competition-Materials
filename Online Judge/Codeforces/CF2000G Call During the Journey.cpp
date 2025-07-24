#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,t0,t1,t2;
    cin>>n>>m>>t0>>t1>>t2;
    struct node{
        int to,next,l1,l2;
    };
    vector<node> edge(m*2+1);
    vector<int> head(n+1);
    int cnt=0;
    auto addedge=[&](int u,int v,int t1,int t2){
        edge[++cnt].to=v;
        edge[cnt].l1=t1;
        edge[cnt].l2=t2;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<=m;i++){
        int u,v,l1,l2;
        cin>>u>>v>>l1>>l2;
        addedge(u,v,l1,l2);
        addedge(v,u,l1,l2);
    }
    auto dijstra=[&](int s){
        vector<int> dis(n+1,0x3f3f3f3f),vis(n+1);
        dis[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        while(q.size()){
            int u=q.top().second;
            q.pop();
            if(vis[u])
                continue;
            vis[u]=1;
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                int new_dis=dis[u]+edge[i].l2;
                if(t0-(dis[u]+edge[i].l1)>=t2||t0-dis[u]<=t1)
                    new_dis=min(new_dis,dis[u]+edge[i].l1);
                else new_dis=min(new_dis,t0-t1+edge[i].l1);
                if(dis[v]>new_dis){
                    dis[v]=new_dis;
                    q.push({dis[v],v});
                }
            }
        }
        return dis[1];
    };
    int ans=t0-dijstra(n);
    cout<<(ans<0?-1:ans)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}