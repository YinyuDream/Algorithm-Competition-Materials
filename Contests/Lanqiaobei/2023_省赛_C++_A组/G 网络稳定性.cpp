#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,q;
struct _edge{
    int u,v,w;
}_krusual[maxn];
bool operator <(_edge a,_edge b){
    return a.w>b.w;
}
int un[maxn];
int find(int x){
    return un[x]==x?x:un[x]=find(un[x]);
}
struct node{
    int to,next,w;
}edge[maxn];
int head[maxn];
void add(int u,int v,int w)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    edge[k].w=w;
    head[u]=k;
}
int fa[maxn][20],minx[maxn][20],dep[maxn],book[maxn];
void dfs(int u,int f)
{
    book[u]=1;
    fa[u][0]=f;
    for(int i=1;i<=19;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=1;i<=19;i++)
        minx[u][i]=min(minx[u][i-1],minx[fa[u][i-1]][i-1]);
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to,w=edge[i].w;
        if(v==f)
            continue;
        dep[v]=dep[u]+1;
        minx[v][0]=w;
        dfs(v,u);
    }
}
int query(int u,int v)
{
    int ans=0x3f3f3f3f;
    if(dep[u]<dep[v])
        swap(u,v);
    for(int i=19;i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]){
            ans=min(ans,minx[u][i]);
            u=fa[u][i];
        }
    if(u==v)
        return ans;
    for(int i=19;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            ans=min(ans,min(minx[u][i],minx[v][i]));
            u=fa[u][i];
            v=fa[v][i];
        }
    return min(ans,min(minx[u][0],minx[v][0]));
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        _krusual[i]={u,v,w};
    }
    sort(_krusual+1,_krusual+m+1);
    for(int i=1;i<=n;i++)
        un[i]=i;
    for(int i=1;i<=m;i++){
        int u=_krusual[i].u,v=_krusual[i].v,w=_krusual[i].w;
        if(find(u)!=find(v)){
            un[find(u)]=find(v);
            add(u,v,w);
            add(v,u,w);
        }
    }
    memset(minx,0x3f,sizeof(minx));
    for(int i=1;i<=n;i++)
        if(!book[i])
            dfs(i,i);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v))
            cout<<-1<<endl;
        else cout<<query(u,v)<<endl;
    }
    return 0;
}