#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
const ll p=998244353;
int main(){
    vector<ll> f(N+1),g(N+1),sum_f(N+1),sum_g(N+1),ans(N+1);
    f[1]=f[2]=g[1]=g[2]=1;
    for(int i=3;i<=N;i++){
        f[i]=(f[i-1]+f[i-2])%p;
        g[i]=f[i]*f[i]%p;
    }
    for(int i=1;i<=N;i++){
        sum_f[i]=(sum_f[i-1]+f[i])%p;
        sum_g[i]=(sum_g[i-1]+g[i])%p;
    }
    for(int i=1;i<=N;i++){
        ans[i]=ans[i-1];
        ans[i]=(ans[i]+i*f[i]%p*f[i]%p)%p;
        ans[i]=(ans[i]-2*f[i]%p*sum_f[i]%p)%p;
        ans[i]=(ans[i]+sum_g[i])%p;
        ans[i]=(ans[i]+p)%p;
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}