#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int _=1;_<=10000;_++){
        for(int i=1;i<n;i++){
            if(a[i+1]>a[i]){
                a[i]++;
                a[i+1]--;
            }
        }
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*a[i]%mod;
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