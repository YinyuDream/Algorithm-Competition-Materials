#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=n-1;i>=0;i--){
        if(sum+a[i]>k){
            cout<<k-sum<<endl;
            return;
        }
        sum+=a[i];
    }
    if(sum<=k){
        cout<<k-sum<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}