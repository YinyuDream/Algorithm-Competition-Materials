#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{int x,y;ll z;}a[5000010];
int T,n,ok,tot;
int f[2010],dp[2010][2010];
ll x[2010],y[2010];
ll getdis(int u,int v){return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);}
bool cmp(const node &x,const node &y){return x.z>y.z;}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
    tot=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            a[++tot].x=i;
            a[tot].y=j;
            a[tot].z=getdis(i,j);
        }
    sort(a+1,a+tot+1,cmp);
    //for (int i=1;i<=n;i++) f[i]=0;
    //for (int i=1;i<=n;i++)
    //    for (int j=1;j<=n;j++) dp[i][j]=0;
    int k=0;
    for (int t=1;t<=tot;t++)
    {
        while (a[k+1].z>a[t].z)
        {
            k++;
            if (dp[a[k].x][a[k].y]==0) f[a[k].y]=1;
            if (dp[a[k].y][a[k].x]==0) f[a[k].x]=1;
        }
        //f[i]表示的是在只用到比t号边更长边的情况下 从i是否必胜 
        int i=a[t].x,j=a[t].y;
        if (f[i]==1) dp[i][j]=1;else dp[i][j]=0;
        if (f[j]==1) dp[j][i]=1;else dp[j][i]=0;
    }
    ok=0;
    for (int i=2;i<=n;i++) if (dp[i][1]==0) ok=1;
    if (ok) puts("YES");else puts("NO");
}
