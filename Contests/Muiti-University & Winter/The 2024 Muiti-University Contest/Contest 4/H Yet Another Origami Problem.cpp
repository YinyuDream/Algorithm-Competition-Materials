#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin()+1,a.end());
    if(n==1){
        cout<<0<<endl;
        return ;
    }
    ll gcd=a[2]-a[1];
    for(int i=3;i<=n;i++)
        gcd=__gcd(gcd,a[i]-a[i-1]);
    cout<<gcd<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}