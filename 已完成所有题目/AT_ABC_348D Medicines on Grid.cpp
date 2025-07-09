#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
int n,m,k;
int qx,qy,zx,zy;
int mapp[maxn][maxn],dis[maxn][maxn],vis[maxn][maxn];
int medx[maxn],medy[maxn],medw[maxn],len[maxn][maxn];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct node{
    int x,y;
    node(int _x,int _y){
        x=_x,y=_y;
    }
};
int cnt_edge;
struct edge{
    int to,next;
}edge[maxn*maxn];
int head[maxn];
void add(int u,int v)
{
    edge[++cnt_edge].to=v;
    edge[cnt_edge].next=head[u];
    head[u]=cnt_edge;
}
void bfs(int pos)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<node>q;
    q.push(node(medx[pos],medy[pos]));
    dis[medx[pos]][medy[pos]]=0;
    vis[medx[pos]][medy[pos]]=1;
    while(q.size()){
        node u=q.front();
        q.pop();
        for(int i=0;i<=3;i++){
            int nx=u.x+dx[i],ny=u.y+dy[i];
            if(!nx||!ny||nx>n||ny>m||mapp[nx][ny]==-1||vis[nx][ny]==1)
                continue;
            dis[nx][ny]=dis[u.x][u.y]+1;
            q.push(node(nx,ny));
            vis[nx][ny]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mapp[i][j]>0)
                len[pos][mapp[i][j]]=len[mapp[i][j]][pos]=dis[i][j];
}
int can[maxn];
void solve()
{
    queue<int>q;
    q.push(mapp[qx][qy]);
    can[mapp[qx][qy]]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(!can[v]){
                can[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            ch=getchar();
            while(ch!='#'&&ch!='.'&&ch!='S'&&ch!='T')
                ch=getchar();
            if(ch=='S')
                qx=i,qy=j;
            if(ch=='T')
                zx=i,zy=j;
            if(ch=='#')
                mapp[i][j]=-1;
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        int x,y,w;
        cin>>x>>y>>w;
        mapp[x][y]=i;
        medx[i]=x;
        medy[i]=y;
        medw[i]=w;
    }
    if(mapp[qx][qy]==0){
        cout<<"No";
        return 0;
    }
    if(mapp[zx][zy]==0){
        medx[++k]=zx;
        medy[k]=zy;
        mapp[zx][zy]=k;
    }
    bfs(mapp[qx][qy]);
    if(vis[zx][zy]==0){
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=k;i++)
        bfs(i);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i==j)continue;
            if(medw[i]>=len[i][j])
                add(i,j);
        }
    }
    solve();
    if(can[mapp[zx][zy]])cout<<"Yes";
    else cout<<"No";
    return 0;
}