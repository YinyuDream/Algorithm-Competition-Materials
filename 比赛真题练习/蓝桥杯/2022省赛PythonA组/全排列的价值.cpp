#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int n;
ll f[maxn],fac[maxn];
int main(){
    cin>>n;
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i%p;
        f[i]=(1ll*i*f[i-1]%p+1ll*i*(i-1)/2%p*fac[i-1]%p)%p;
    }
    cout<<f[n];
    return 0;
}