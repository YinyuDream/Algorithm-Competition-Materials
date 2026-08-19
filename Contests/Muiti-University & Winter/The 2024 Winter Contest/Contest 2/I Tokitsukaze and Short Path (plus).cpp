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
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=ans+i*a[i];
    }
    cout<<ans*4<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}