#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define mod 1000000007
using namespace std;
typedef long long ll;
int T,n,m,edgenum,u,v;
int vet[N],Next[N],head[N],fa[N],a[N];
ll ans,len[N],f0[N],f1[N],g0[N],g1[N];
void add(int u,int v,ll w)
{
    vet[++edgenum]=v;
    Next[edgenum]=head[u];
    head[u]=edgenum;
    len[edgenum]=w;
}
int read()
{
    char ch=getchar();int x=0;
    while (ch>'9'||ch<'0') ch=getchar();
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int getfather(int x){if (fa[x]!=x) fa[x]=getfather(fa[x]);return fa[x];}
void dfs(int u,int fa)
{
    //printf("%d\n",u);
    f0[u]=f1[u]=g0[u]=g1[u]=0;
    if (a[u]==0) g0[u]=1;else g1[u]=1;
    for (int e=head[u];e;e=Next[e])
    {
        int v=vet[e];
        if (v!=fa)
        {
            dfs(v,u);
            ans+=f0[u]*g1[v]%mod+f1[v]*g0[u]%mod+len[e]*g0[u]%mod*g1[v]%mod;ans%=mod;
            ans+=f1[u]*g0[v]%mod+f0[v]*g1[u]%mod+len[e]*g1[u]%mod*g0[v]%mod;ans%=mod;
            f0[u]+=f0[v]+len[e]*g0[v]%mod;f0[u]%=mod;
            f1[u]+=f1[v]+len[e]*g1[v]%mod;f1[u]%=mod;
            g0[u]+=g0[v];g0[u]%=mod;
            g1[u]+=g1[v];g1[u]%=mod;
        }
    }
}
int main()
{
        n=read();m=read();
        edgenum=0;
        for (int i=1;i<=n;i++) head[i]=0;
        for (int i=1;i<=n;i++) a[i]=read();
        for (int i=1;i<=n;i++) fa[i]=i;
        for (int i=1,d=2;i<=m;i++,d=d*2%mod)
        {
            u=read();v=read();
            int x=getfather(u),y=getfather(v);
            if (x!=y){fa[x]=y;add(u,v,d);add(v,u,d);}
        }
        //puts("ok");
        ans=0;
        dfs(1,0);
        printf("%lld\n",ans);
}
