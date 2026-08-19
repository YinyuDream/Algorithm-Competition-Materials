#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll gcd=a[0];
    for(int i=1;i<n;i++)
        gcd=__gcd(gcd,a[i]);
    ll ans=gcd;
    vector<ll> pre(n),suf(n);
    pre[0]=a[0];
    for(int i=1;i<n;i++)
        pre[i]=__gcd(pre[i-1],a[i]);
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
        suf[i]=__gcd(suf[i+1],a[i]);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}