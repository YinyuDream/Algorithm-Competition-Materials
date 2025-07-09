#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll ex_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll res=ex_gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return res;
}
void solve(){
    int n;
    ll k,sum=0;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll mx=*max_element(a.begin()+1,a.end());
    int ans=0;
    auto check=[&](int x){
        ll y=sum/x-mx+(sum%x!=0);
        y=max(0ll,y);
        ll delta=x*(mx+y)-sum;
        return delta<=k;
    };
    for(int i=1;i<=n;i++){
        if(check(i)){
            ans=max(ans,i);
        }
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