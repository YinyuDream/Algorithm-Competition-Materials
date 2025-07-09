#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    ll l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1),f(n+1);
    vector<ll> sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(sum[i]<l){
            f[i]=f[i-1];
            continue;
        }
        int pos=upper_bound(sum.begin(),sum.begin()+i,sum[i]-l)-sum.begin()-1;
        if(sum[i]-sum[pos]>r){
            f[i]=f[i-1];
        }else{
            f[i]=f[pos]+1;
        }
    }
    cout<<f[n]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}