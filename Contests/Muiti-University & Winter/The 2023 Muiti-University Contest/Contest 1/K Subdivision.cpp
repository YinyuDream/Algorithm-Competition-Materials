#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,cnt_Edge=1,k;
long long ans;
struct node{
    int from,to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v){
    edge[++cnt_Edge].to=v;
    edge[cnt_Edge].from=u;
    edge[cnt_Edge].next=head[u];
    head[u]=cnt_Edge;
}
int dis[maxn],deg[maxn];
bool book[maxn],book_edge[maxn],is_leaf[maxn];
queue<int>q;
void bfs()
{
    memset(dis,0x3f,sizeof dis);
    book[1]=true;
    dis[1]=0;
    q.push(1);
    while(q.size()){
        int u=q.front();
        q.pop();
        bool check_leaf=true;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(book[v]==false){
                check_leaf=false;
                book[v]=true;
                dis[v]=dis[u]+1;
                q.push(v);
                book_edge[i]=book_edge[i^1]=true;
            }
        }
        is_leaf[u]=check_leaf;
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
        deg[u]++;
        deg[v]++;
    }
    bfs();
    for(int i=1;i<=n;i++){
        if(dis[i]<=k){
            ans++;
        }
        if(dis[i]<k&&is_leaf[i]&&deg[i]==1){
            ans+=k-dis[i];
        }
    }
    for(int i=2;i<=cnt_Edge;i+=2){
        if(book_edge[i]==false&&dis[edge[i].from]!=0x3f3f3f3f){
            if(dis[edge[i].from]<k)ans+=k-dis[edge[i].from];
            if(dis[edge[i].to]<k)ans+=k-dis[edge[i].to];
        }
    }
    cout<<ans;
    return 0;
}