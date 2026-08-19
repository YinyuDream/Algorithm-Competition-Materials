#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<n-1;i++){
        if(a[i]>2*a[0]){
            ans+=4ll*a[0]*(n-i-1);
        }else{
            ans+=2ll*a[i]*(n-i-1);
        }
    }
    cout<<2*ans+4ll*a[0]*(n-1)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}