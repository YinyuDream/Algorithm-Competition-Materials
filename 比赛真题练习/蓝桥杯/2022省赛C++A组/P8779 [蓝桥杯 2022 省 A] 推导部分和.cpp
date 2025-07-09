#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,q,k;
struct node{
  int to,next;
  ll wt;
}edge[maxn];
int head[maxn],fa[maxn],book[maxn];
ll dis[maxn];
void add(int u,int v,ll w)
{
  edge[++k].to=v;
  edge[k].next=head[u];
  edge[k].wt=w;
  head[u]=k;
}
int find(int u)
{
  return u==fa[u]?u:fa[u]=find(fa[u]);
}
bool query(int u,int v)
{
  int fx=find(u),fy=find(v);
  return fx==fy;
}
void merge(int u,int v)
{
  int fx=find(u),fy=find(v);
  fa[fx]=fy;
}
void dfs(int u,int f)
{
  book[u]=1;
  for(int i=head[u];i;i=edge[i].next){
    int v=edge[i].to;
    if(v!=f){
      dis[v]=dis[u]+edge[i].wt;
      dfs(v,u);
    }
  }
}
int main()
{
  cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
    fa[i]=i;
  for(int i=1;i<=m;i++){
    int l,r;
    ll s;
    cin>>l>>r>>s;
    if(!query(l-1,r)){
      merge(l-1,r);
      add(l-1,r,s);
      add(r,l-1,-s);
    }
  }
  for(int i=1;i<=n;i++){
    if(!book[i]){
      dfs(i,i);
    }
  }
  for(int i=1;i<=q;i++){
    int l,r;
    cin>>l>>r;
    if(!query(l-1,r)){
      cout<<"UNKNOWN"<<endl;
      continue;
    }
    cout<<dis[r]-dis[l-1]<<endl;
  }
  return 0;
}