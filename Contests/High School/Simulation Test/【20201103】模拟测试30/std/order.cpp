#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-falign-jumps")
#include<bits/stdc++.h>
#define rint register int
#define in inline
#define ll long long
using namespace std;
int a,b,c,d,n,m;
int head[500010],k;
ll dist[3][500010],minn=1e17;
bool book[500010];
struct node
{
    int to,next;
    ll w;
}edge[2000010];
struct dl
{
    int num; ll dis;
    friend bool operator < (dl a,dl b) { return a.dis>b.dis; }
};
in ll read()
{
    ll x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return x*f;
}
in void adde(int u,int v,ll w)
{
    edge[++k].to=v; edge[k].next=head[u]; edge[k].w=w; head[u]=k;
}
in void dij(int s,ll dis[])
{
    for(rint i=1;i<=n;i++) dis[i]=1e17,book[i]=0;
    priority_queue<dl> q; q.push((dl){s,0}); dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().num; q.pop();
        if(book[u]) continue; book[u]=1;
        if(s==a&&book[b]&&book[c]&&book[d]) return;
        if(s==b&&book[c]&&book[d]) return;
        if(s==c&&book[d]) return;
        for(rint i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w&&!book[v])
            {
                dis[v]=dis[u]+edge[i].w;
                q.push((dl){v,dis[v]});
            }
        }
    }
}
int main()
{
    a=read(); b=read(); c=read(); d=read(); n=read();
    b+=a; c+=b; d+=c; n+=d;
    a++; b++; c++; d++; n++;//差分后只有a b c d四个点上是1 
    m=read();
    for(rint i=1;i<=m;i++)
    {
        int u=read(),v=read(); v++;//差分 r+1 
        ll w=read();
        adde(u,v,w); adde(v,u,w);
    }
    //要跑三组最短路 a~b c~d 和 a~c b~d 和 a~d b~c
    dij(a,dist[0]); dij(b,dist[1]); dij(c,dist[2]);
    if(dist[0][b]+dist[2][d]<minn) minn=dist[0][b]+dist[2][d];
    if(dist[0][c]+dist[1][d]<minn) minn=dist[0][c]+dist[1][d];
    if(dist[0][d]+dist[1][c]<minn) minn=dist[0][d]+dist[1][c];
    printf("%lld",minn);
    return 0;
}
