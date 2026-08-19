#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1e6+10;
const int E = 1e6 + 10;
struct Edge{
    int nxt, to;
}e[E*2];
int head[N], cnt = 1;
bool vis[N];
int val[N], ringPt1,    ringPt2,    not_pass;
long long dp[2][N];
void add(int u,int v){
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}
void getDP(int rt, int fa)
{
    dp[0][rt] = 0,  dp[1][rt] = val[rt];
    for(int i=head[rt];i;i=e[i].nxt)
    {
        if(e[i].to == fa)   continue;
        if(i == not_pass || i == (not_pass^1))  continue;
        getDP(e[i].to, rt);
        dp[0][rt] += max(dp[0][e[i].to], dp[1][e[i].to]);
        dp[1][rt] += dp[0][e[i].to];
    }
}
void dfs(int rt, int fa)
{
    vis[rt] = 1;
    for(int i=head[rt];i;i=e[i].nxt)
    {
        if(e[i].to == fa)   continue;
        if(!vis[e[i].to])   dfs(e[i].to, rt);
        else{
            not_pass = i;
            ringPt1 = e[i].to;  ringPt2 = rt;
        }
    }
}
int main()
{freopen("a.in","r",stdin);
freopen("rig.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1,y;i<=n;i++)
        scanf("%d %d",&val[i], &y), add(i,y),   add(y,i);
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])  continue;
        dfs(i, -1);
        getDP(ringPt1, -1);
        long long tmp = dp[0][ringPt1];
        getDP(ringPt2, -1);
        ans += max(tmp, dp[0][ringPt2]);
    }
    cout<<ans<<endl;
}
