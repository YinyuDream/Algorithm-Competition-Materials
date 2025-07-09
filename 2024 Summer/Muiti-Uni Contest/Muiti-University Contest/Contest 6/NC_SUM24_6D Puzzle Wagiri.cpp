#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,tot;
struct e_{
    int u,v;
    string opt;
}e[maxn];
struct node{
    int to,next,wt;
}edge[maxn];
int head[maxn],fa[maxn],ans[maxn],in[maxn];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
    int fx=find(u),fy=find(v);
    if(fx!=fy)fa[fx]=fy,tot--;
}
void add(int u,int v,int w)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    edge[k].wt=w;
    head[u]=k;
}
int father[maxn],low[maxn],dfn[maxn],dfs_clock,cnt_bridge;
void tarjan(int u, int ffa,int eee) {
  father[u] = ffa;
  low[u] = dfn[u] = ++dfs_clock;
  for (int i = head[u]; i ; i=edge[i].next) {
    int v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v, u,edge[i].wt);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        ans[edge[i].wt]=0;
          //cout<<eee<<"Dw"<<endl;
        ++cnt_bridge;
      }
    } else if (dfn[v] < dfn[u] && v != ffa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
int main(){
    cin>>n>>m;
    tot=n;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].opt;
        if(e[i].opt=="Lun"){
            add(e[i].v,e[i].u,i);
            add(e[i].u,e[i].v,i);
            in[e[i].u]++,in[e[i].v]++;
            ans[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]&&in[i])
            tarjan(i,0,-1);
    for(int i=1;i<=m;i++){
        if(ans[i]==1){
            //cout<<i<<"Dw";
            merge(e[i].u,e[i].v);
        }
    }
    for(int i=1;i<=m;i++){
        if(e[i].opt=="Qie"){
            if(find(e[i].u)!=find(e[i].v)){
                merge(e[i].u,e[i].v);
                ans[i]=1;
            }
        }
    }
    if(tot!=1){
        cout<<"NO"<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(ans[i])
            cnt++;
    cout<<"YES"<<endl<<cnt<<endl;
    for(int i=1;i<=m;i++)
        if(ans[i])
            cout<<e[i].u<<" "<<e[i].v<<endl;
    return 0;
}