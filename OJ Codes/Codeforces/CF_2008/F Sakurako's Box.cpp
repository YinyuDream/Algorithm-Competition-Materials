#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=1e9+7;
ll ksm(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    ll sum=0,tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        tot+=a[i]*a[i];
        tot%=p;
    }
    sum%=p;
    sum=sum*sum-tot;
    sum=(sum%p+p)%p;
    sum=sum*ksm(2,p-2,p)%p;
    cout<<2*sum*ksm(n,p-2,p)%p*ksm(n-1,p-2,p)%p<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}