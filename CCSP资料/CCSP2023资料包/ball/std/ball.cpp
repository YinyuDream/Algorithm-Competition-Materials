#include<bits/stdc++.h>
using namespace std;
#define P 998244353
#define ll long long
#define MAXN 2005
int f[MAXN],g[MAXN],d1[MAXN],d2[MAXN],p[MAXN];
int Pow(int x,int y)
{
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
    return s;
}
int C(int x,int y)
{
    return (ll)f[x]*g[y]%P*g[x-y]%P;
}
void work1(int *d,int n)
{
    int i;
    for(i=0;i<=n;i++)d[i]=(ll)C(n,i)*f[i]%P;
}
void work2(int *d,int n)
{
    int i,j;
    for(i=0;i<=n<<1;i++)
    for(j=max(0,i-n);j<<1<=i;j++)d[i]=(d[i]+(ll)C(i,j<<1)*C(n,j)%P*f[n-j]%P*g[n+j-i]%P*f[j<<1]%P*p[j])%P;
}
int main()
{
    int n,m,a,b,k,s,i,ans=0;
    cin>>n>>m>>a>>b>>k>>s;
    if(a>b)
    {
        swap(n,m);
        swap(a,b);
    }
    for(i=f[0]=1;i<MAXN;i++)f[i]=(ll)f[i-1]*i%P;
    for(g[MAXN-1]=Pow(f[MAXN-1],P-2),i=MAXN-2;~i;i--)g[i]=(ll)g[i+1]*(i+1)%P;
    for(i=p[0]=1;i<MAXN;i++)p[i]=(ll)p[i-1]*(P+1>>1)%P;
    if(s==1)
    {
        work1(d1,b-a);
        work1(d2,a);
    }
    else
    {
        work2(d1,b-a);
        work2(d2,a);
    }
    for(i=0;i<=k&&i<=m;i++)ans=(ans+(ll)C(m,i)*C(n+m-i,k-i)%P*d1[i]%P*d2[k-i])%P;
    cout<<ans<<endl;
    return 0;
}