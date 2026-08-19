#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    ll v;
    cin>>n>>m>>v;
    vector<ll> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    vector<int> f(n+1),g(n+2);
    for(int i=1;i<=n;i++){
        int pos=upper_bound(sum.begin()+1,sum.end(),sum[i]-v)-sum.begin()-1;
        if(sum[i]-sum[pos]>=v){
            f[i]=f[pos]+1;
        }
    }
    reverse(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int pos=upper_bound(sum.begin()+1,sum.end(),sum[i]-v)-sum.begin()-1;
        if(sum[i]-sum[pos]>=v){
            g[i]=g[pos]+1;
        }
    }
    reverse(g.begin()+1,g.end()-1);
    reverse(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(f[n]<m){
        cout<<-1<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(f[i-1]+g[i+1]<m){
            continue;
        }
        int l=i,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(f[i-1]+g[mid+1]>=m){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,sum[r]-sum[i-1]);
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}