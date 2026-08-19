#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
inline int add(int x,int y,int m) { return (x+=y)>=m ? x-m : x; }
int m,a[MAXN];
vector<pair<int,int>> e[MAXN];
vector<pair<int,int>> dp[MAXN],fp[MAXN];
int ans[MAXN][MAXN];
void merge(int u,int v,int w)
{
    for(int i=0;i<m;i++)
        ans[u][i]=max(ans[u][i],ans[v][i]);
    for(auto& x : dp[u])
        for(auto& y : fp[v])
        {
            int i=add(x.first,y.first,m);
            ans[u][i]=max(ans[u][i],x.second+y.second+w);
        }
    for(auto& x : fp[u])
        for(auto& y : dp[v])
        {
            int i=add(x.first,y.first,m);
            ans[u][i]=max(ans[u][i],x.second+y.second+w);
        }
    static int tmp[MAXN];
    memset(tmp,-1,m*sizeof(int));
    for(auto& x : fp[u])
        tmp[x.first]=max(tmp[x.first],x.second);
    for(auto& y : fp[v])
        tmp[y.first]=max(tmp[y.first],y.second+w);
    for(auto& x : dp[u])
        for(auto& y : dp[v])
        {
            int i=add(x.first,y.first,m);
            tmp[i]=max(tmp[i],x.second+y.second+w);
        }
    fp[u].clear();
    for(int i=0;i<m;i++)if(tmp[i]>=0)
        fp[u].emplace_back(i,tmp[i]);
    memset(tmp,-1,m*sizeof(int));
    for(auto& x : dp[u])
        tmp[x.first]=max(tmp[x.first],x.second);
    for(auto& y : dp[v])
        tmp[y.first]=max(tmp[y.first],y.second+w);
    dp[u].clear();
    for(int i=0;i<m;i++)if(tmp[i]>=0)
        dp[u].emplace_back(i,tmp[i]);
}
void dfs(int u,int fa)
{
    dp[u].emplace_back(a[u],0);
    for(auto& t : e[u])
    {
        int v,w;
        tie(v,w)=t;
        if(v==fa)continue;
        dfs(v,u);
        merge(u,v,w);
    }
}
int main()
{
    int n,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    dfs(1,0);
    while(q--)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        printf("%u\n",ans[x][k]*2);
    }
    return 0;
}
