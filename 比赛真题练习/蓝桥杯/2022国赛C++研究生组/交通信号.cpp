#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,s,t,k;
struct node{
    int to,next;
    ll g,r,y;
    int dir;
}edge[maxn];
struct dij{
    int id;
    ll d;
    dij(int _id,ll _d){
        id=_id,d=_d;
    }
};
bool operator <(dij u,dij v){
    return u.d>v.d;
}
int head[maxn];
void add(int u,int v,ll g,ll r,ll y,int dir)
{
    edge[++k]={v,head[u],g,r,y,dir};
    head[u]=k;
}
int book[maxn];
ll dis[maxn];
void dijkstra()
{
    memset(dis,0x3f,sizeof dis);
    priority_queue<dij> q;
    q.push(dij(s,0));
    dis[s]=0;
    while(q.size()){
        dij u=q.top();
        q.pop();
        if(book[u.id])
            continue;
        book[u.id]=1;
        for(int i=head[u.id];i;i=edge[i].next){
            int v=edge[i].to,dir=edge[i].dir;
            ll T=edge[i].g+edge[i].r+2*edge[i].y,remind=dis[u.id]%T;
            if(book[v])continue;
            ll disv=dis[u.id];
            if(dir==1){
                if(remind<edge[i].g)disv+=edge[i].y;
                else disv+=edge[i].y+T-remind;
            }else{
                if(remind<edge[i].g+edge[i].y+edge[i].r&&remind>=edge[i].g+edge[i].y)disv+=edge[i].y;
                else if(remind<edge[i].g+edge[i].y)disv+=edge[i].y+edge[i].y+edge[i].g-remind;
                else disv+=edge[i].y+T-remind+edge[i].y+edge[i].g;
            }
            if(dis[v]>disv){
                dis[v]=disv;
                q.push(dij(v,disv));
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int u,v,g,r,y;
        cin>>u>>v>>g>>r>>y;
        add(u,v,g,r,y,1);
        add(v,u,g,r,y,-1);
    }
    dijkstra();
    cout<<(dis[t]==0x3f3f3f3f3f3f3f3fll?-1:dis[t]);
    return 0;
}