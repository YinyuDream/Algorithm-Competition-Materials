#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn],f[maxn],g[maxn],b[maxn],help[maxn],sum[maxn];
long long cnt;
int qpow(int x,int b)
{
    if(b==0)return 1;
    int t=qpow(x,b/2)%k;
    t=1ll*t*t%k;
    if(b&1)t=1ll*t*x%k;
    return t;
}
void lsh()
{
    for(int i=1;i<=n;i++)
        b[i]=f[i],b[i+n]=g[i];
    for(int i=1;i<=n*2;i++)
        help[i]=b[i];
    sort(help+1,help+n*2+1);
    int cnt=unique(help+1,help+n*2+1)-help-1;
    for(int i=1;i<=n*2;i++)
        b[i]=lower_bound(help+1,help+cnt+1,b[i])-help;
    for(int i=1;i<=n;i++)
        f[i]=b[i],g[i]=b[i+n];
}
void update(int x)
{
    for(int i=x;i<=n*2;i+=i&(-i))
        sum[i]++;
}
int query(int x)
{
    int ans=0;
    for(int i=x;i;i-=i&(-i))
        ans+=sum[i];
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        f[i]=qpow(i,a[i]),
        g[i]=qpow(a[i],i);
    lsh();
    for(int i=n;i>=1;i--)
        cnt+=query(f[i]-1),
        update(g[i]);
    printf("%lld",cnt);
    return 0;
}
