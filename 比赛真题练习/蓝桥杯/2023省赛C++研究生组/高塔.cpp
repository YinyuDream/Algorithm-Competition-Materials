#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll p=998244353;
int n,m;
ll ans;
ll a[maxn],f[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            for(int k=1;j-k>=i-1;k++){
                f[i][j]+=f[i-1][j-k]*a[i]*k;
                f[i][j]%=p;
            }
        }
    }
    for(int i=n;i<=m;i++)
        ans=(ans+f[n][i])%p;
    for(int i=1;i<n;i++)
        ans=(ans+f[i][m])%p;
    cout<<ans<<endl;
    return 0;
}