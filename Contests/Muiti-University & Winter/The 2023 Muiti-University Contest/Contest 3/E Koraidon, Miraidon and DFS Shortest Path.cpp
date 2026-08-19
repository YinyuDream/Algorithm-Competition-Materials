#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,cnt_edge;
struct node{
    int to,next,fr;
}edge[maxn];
int head[maxn],book_edge[maxn];
void add(int u,int v)
{
    edge[++cnt_edge].to=v;
    edge[cnt_edge].fr=u;
    edge[cnt_edge].next=head[u];
    head[u]=cnt_edge;
}
int dis[maxn],book[maxn],fa[maxn][20];
void bfs()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        dis[i]=0x3f3f3f3f,book[i]=0;
    book[1]=true;
    dis[1]=0;
    q.push(1);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(book[v]==false){
                book[v]=true;
                dis[v]=dis[u]+1;
                q.push(v);
                book_edge[i]=true;
            }
        }
    }
}
void dfs(int x)
{
    book[x]=true;
    for(int i=1;(1<<i)<=dis[x];i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=head[x];i;i=edge[i].next)
    {
        if(!book[edge[i].to]&&book_edge[i])
        {
            fa[edge[i].to][0]=x;
            dfs(edge[i].to);
        }
    }
}
int LCA(int x,int y)
{
    if(dis[x]<dis[y])
        swap(x,y);
    int h=dis[x]-dis[y];
    for(int i=0;(1<<i)<=h;i++)
        if((1<<i)&h)
            x=fa[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            add(u,v);
        }
        bfs();
        for(int i=1;i<=n;i++)
            book[i]=0;
        fa[1][0]=1;
        dfs(1);
        for(int i=1;i<=cnt_edge;i++){
            if(!book_edge[i]){
                int u=edge[i].fr,v=edge[i].to,lca=LCA(edge[i].fr,edge[i].to);
                if(lca!=v&&dis[v]-dis[u]!=1){
                    cout<<"No"<<endl;
                    goto flag;
                }
            }
        }
        cout<<"Yes"<<endl;
        flag:;
        for(int i=1;i<=cnt_edge;i++)
            edge[i].fr=edge[i].to=edge[i].next=book_edge[i]=0;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=19;j++)
                fa[i][j]=0;
        cnt_edge=0;
    }
    return 0;
}