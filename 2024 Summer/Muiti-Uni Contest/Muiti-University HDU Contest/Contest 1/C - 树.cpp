#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn=5e5+10;
int n,edge_tot,dfn;
struct node{
    int to,next;
}edge[2*maxn];
int head[maxn],sz[maxn],son[maxn],ord[maxn],old[maxn];
ull mx,a[maxn],sum[maxn],sum_pw2[maxn*2],tot[maxn*2],ans[maxn];
multiset<ull> s[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void add_edge(int u,int v){
    edge[++edge_tot].to=v;
    edge[edge_tot].next=head[u];
    head[u]=edge_tot;
}
void add(int pos,ull val, ull *c){
    for(int i=pos;i<=mx;i+=i&-i)
        c[i]+=val;
}
ull query(int l,int r, ull *c){
    ull res=0;
    for(int i=r;i;i-=i&-i)
        res+=c[i];
    for(int i=l-1;i;i-=i&-i)
        res-=c[i];
    return res;
}
void dfs(int u,int fa){
    ord[u]=++dfn;
    old[dfn]=u;
    sz[u]=1;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])
            son[u]=v;
    }
}
void solve(int u,int fa,bool keep){
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa||v==son[u]) continue;
        solve(v,u,false);
    }
    if(son[u]){
        solve(son[u],u,true);
    }
    
    ull total=sum[ord[son[u]]+sz[son[u]]-1]-sum[ord[son[u]]-1];
    ans[u]-=a[u]*total;
    ans[u]+=query(a[u]+1,mx,sum_pw2);
    ans[u]+=query(1,a[u],tot)*a[u]*a[u];
    add(a[u],a[u]*a[u],sum_pw2);
    add(a[u],1,tot);
    
    total+=a[u];
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa||v==son[u]) continue;
        for(int j=ord[v];j<ord[v]+sz[v];j++){
            ans[u]-=total*a[old[j]];
            ans[u]+=query(a[old[j]]+1,mx,sum_pw2);
            ans[u]+=query(1,a[old[j]],tot)*a[old[j]]*a[old[j]];
        }
        for(int j=ord[v];j<ord[v]+sz[v];j++){
            add(a[old[j]],a[old[j]]*a[old[j]],sum_pw2);
            add(a[old[j]],1,tot);
        }
        total+=sum[ord[v]+sz[v]-1]-sum[ord[v]-1];
    }
    ans[u]*=2;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa) continue;
        ans[u]+=ans[v];
    }
    if(!keep){
        for(int i=ord[u];i<ord[u]+sz[u];i++){
            add(a[old[i]],-a[old[i]]*a[old[i]],sum_pw2);
            add(a[old[i]],-1,tot);
        }
    }
    
}
void solve()
{
    
    n=read();
    for(int i=1;i<n;i++){
        int u,v;
        u=read(),v=read();
        add_edge(u,v);
        add_edge(v,u);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]+1);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        sum[ord[i]]=a[i];
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    solve(1,0,true);
    ull res=0;
    for(int i=1;i<=n;i++)
        res^=ans[i];
    cout<<res<<endl;
}
int main(){
    solve();   
    return 0;
}