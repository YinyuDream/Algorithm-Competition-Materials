#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int p=998244353;
int n,s[maxn],t[maxn];
int ans,f[maxn][maxn],fac[maxn],inv[maxn],finv[maxn];
int C(int a,int b)
{
    return 1ll*fac[a]*finv[b]%p*finv[a-b]%p;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>t[i];
    sort(s+1,s+n+1);
    sort(t+1,t+n+1);
    fac[0]=fac[1]=inv[1]=finv[0]=finv[1]=1;
    for(int i=2;i<maxn;i++){
        fac[i]=1ll*fac[i-1]*i%p;
        inv[i]=(1ll*p-p/i)*inv[p%i]%p;
        finv[i]=1ll*finv[i-1]*inv[i]%p;
    }
    for(int i=0;i<=n;i++)
        f[0][i]=1;
    for(int i=0;i<=n;i++)
        f[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++)
            f[i][i]=(f[i][i]+1ll*C(i,j)*C(i,j))%p;
        for(int j=i+1;j<=n;j++)
            f[j][i]=f[i][j]=(f[i-1][j]+f[i][j-1])%p;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans=(ans+1ll*abs(s[i]-t[j])*f[i-1][j-1]%p*f[n-j][n-i])%p;
    cout<<ans;
    return 0;
}