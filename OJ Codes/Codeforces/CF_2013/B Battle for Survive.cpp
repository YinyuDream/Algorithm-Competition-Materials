#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll sum=0;
    for(int i=1;i<=n-2;i++){
        sum+=a[i];
    }
    a[n-1]-=sum;
    a[n]-=a[n-1];
    cout<<a[n]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}