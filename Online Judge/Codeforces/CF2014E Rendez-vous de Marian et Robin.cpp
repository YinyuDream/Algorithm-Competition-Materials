#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
    ll w;
};
void solve(){
    int n,m,cnt=0,h;
    cin>>n>>m>>h;
    vector<node> edge(m*2+1);
    vector<int> head(n+1),a(n+1);
    for(int i=1;i<=h;i++){
        int x;
        cin>>x;
        a[x]=1;
    }
    auto add_edge=[&](int u,int v,ll w){
        edge[++cnt].to=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    auto dijkstra=[&](int s,vector<array<ll,2>> &dis){
        vector<array<ll,2>> book(n+1);
        priority_queue<pair<ll,array<ll,2>>,vector<pair<ll,array<ll,2>>>,greater<pair<ll,array<ll,2>>>> q;
        for(int i=1;i<=n;i++){
            dis[i][0]=1e18;
            dis[i][1]=1e18;
        }
        dis[s][0]=0;
        if(a[s]){
            dis[s][1]=0;
        }
        q.push({dis[s][0],{s,0}});
        if(a[s]){
            q.push({dis[s][1],{s,1}});
        }
        while(!q.empty()){
            auto [d,u]=q.top();
            q.pop();
            if(book[u[0]][u[1]]){
                continue;
            }
            book[u[0]][u[1]]=1;
            for(int i=head[u[0]];i;i=edge[i].next){
                int v=edge[i].to;
                ll len=edge[i].w;
                if(u[1]==1){
                    len/=2;
                    if(dis[v][1]>dis[u[0]][1]+len){
                        dis[v][1]=dis[u[0]][1]+len;
                        q.push({dis[v][1],{v,1}});    
                    }
                }else{
                    if(dis[v][0]>dis[u[0]][0]+len){
                        dis[v][0]=dis[u[0]][0]+len;
                        q.push({dis[v][0],{v,0}});    
                    }
                    if(a[u[0]]&&dis[v][1]>dis[u[0]][0]+len/2){
                        dis[v][1]=dis[u[0]][0]+len/2;
                        q.push({dis[v][1],{v,1}});
                    }
                }
            }
        }
    };
    vector<array<ll,2>> dis_1(n+1);
    vector<array<ll,2>> dis_n(n+1);
    dijkstra(1,dis_1);
    dijkstra(n,dis_n);
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        ans=min({ans,max(dis_1[i][0],dis_n[i][0]),max(dis_1[i][1],dis_n[i][1]),max(dis_1[i][0],dis_n[i][1]),max(dis_1[i][1],dis_n[i][0])});
    }
    if(ans==1e18){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}