#include <iostream>  
#include <algorithm>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <queue>  
#define M 1000005  
#define LL long long  
using namespace std;  
struct edge  
{  
    int y,ne,v;  
}e[M*2];  
int h[M],v[M],c[M],du[M],q[2*M],n,m,tot,t;  
LL f[M],d[M],a[2*M],b[2*M];  
void Addedge(int x,int y,int v)  
{  
    tot++;  
    e[tot].y=y;  
    e[tot].ne=h[x];  
    h[x]=tot;  
    e[tot].v=v;  
    du[x]++;  
}  
void dfs(int x,int k)  
{  
    v[x]=1,c[x]=k;  
    for (int i=h[x];i;i=e[i].ne)  
    {  
        int y=e[i].y;  
        if (v[y]) continue;  
        dfs(y,k);  
    }  
}  
void Topsort()  
{  
    int l=1,r=0,y;  
    for (int i=1;i<=n;i++)  
        if (du[i]==1) q[++r]=i;  
    while (l<=r)  
    {  
        int x=q[l];  
        for (int i=h[x];i;i=e[i].ne)  
            if (du[y=e[i].y]>1)  
            {  
                du[y]--;  
                d[c[x]]=max(d[c[x]],f[x]+f[y]+e[i].v);  
                f[y]=max(f[y],f[x]+e[i].v);  
                if (du[y]==1) q[++r]=y;  
            }  
        l++;  
    }  
}  
void Dp(int t,int x)  
{  
    int m=0,i,y=x;  
        do  
    {  
        a[++m]=f[y],du[y]=1;  
        for (i=h[y];i;i=e[i].ne)  
            if (du[e[i].y]>1)  
            {  
                y=e[i].y;  
                b[m+1]=b[m]+e[i].v;  
                break;  
            }  
    }while (i);  
    if (m==2)  
    {  
        int l=0;  
        for (int i=h[y];i;i=e[i].ne)  
            if (e[i].y==x) l=max(l,e[i].v);  
        d[t]=max(d[t],f[x]+f[y]+l);  
        return;  
    }  
    for (int i=h[y];i;i=e[i].ne)  
        if (e[i].y==x)  
        {  
            b[m+1]=b[m]+e[i].v;  
            break;  
        }  
    for (int i=1;i<=m;i++)  
    {  
        a[m+i]=a[i];  
        b[m+i]=b[m+1]+b[i];  
    }  
    int l,r;  
    q[l=r=1]=1;  
    for (int i=2;i<2*m;i++)  
    {  
        while (l<=r&&i-q[l]>=m)  
            l++;  
        d[t]=max(d[t],a[i]+a[q[l]]+b[i]-b[q[l]]);  
        while (l<=r&&a[q[r]]+b[i]-b[q[r]]<=a[i])  
            r--;  
        q[++r]=i;  
    }  
}  
int main()  
{  
        scanf("%d",&n);  
    for (int i=1;i<=n;i++)  
    {  
        int x,y;  
        scanf("%d%d",&x,&y);  
        Addedge(x,i,y);  
        Addedge(i,x,y);  
    }  
    memset(v,0,sizeof(v));  
    t=0;  	
    for (int i=1;i<=n;i++)  
        if (!c[i]) dfs(i,++t);  
    Topsort();  
    LL ans=0LL;  
    memset(v,0,sizeof(v));  
    for (int i=1;i<=n;i++)  
        if (du[i]>1&&!v[c[i]])  
        {  
            v[c[i]]=1;  
            Dp(c[i],i);  
            ans+=d[c[i]];  
        }  
    cout<<ans<<endl;  
    return 0;  
}  
