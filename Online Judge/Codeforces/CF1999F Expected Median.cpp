#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mod=1e9+7;
vector<int> fac(maxn),inv(maxn),facinv(maxn);
void init(){
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    facinv[0]=1;
    for(int i=1;i<maxn;i++)
        facinv[i]=1ll*facinv[i-1]*inv[i]%mod;
}
int comb(int x,int y){
    if(x<y)return 0;
    return 1ll*fac[x]*facinv[y]%mod*facinv[x-y]%mod;
}
void solve(){
    int n,k,cnt0=0,cnt1=0;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)cnt0++;
        else cnt1++;
    }
    int ans=0;
    for(int i=0;i<=cnt0;i++)
        if(k-i<=cnt1&&k-i>=0)
            ans=(ans+1ll*comb(cnt0,i)*comb(cnt1,k-i)*(k-i>i))%mod;
    cout<<ans<<endl;
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}