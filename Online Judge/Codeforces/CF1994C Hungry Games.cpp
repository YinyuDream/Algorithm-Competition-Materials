#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1),r(n+1),f(n+2);
    vector<ll> sum(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        auto it=upper_bound(sum.begin(),sum.end(),sum[i-1]+x);
        if(it!=sum.end())
            r[i]=it-sum.begin();
        else r[i]=0;
    }
    for(int i=n;i;i--){
        if(r[i]!=0){
            f[i]=f[r[i]+1]+1;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=f[i];
    cout<<1ll*n*(n+1)/2-ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}