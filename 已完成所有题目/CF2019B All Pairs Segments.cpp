#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<ll,int> mp;
    for(int i=2;i<=n;i++){
        int l=a[i-1],r=a[i];
        if(l+1<=r-1){
            int sz=r-l-1;
            mp[(1ll*i-1)*(n-i+1)]+=sz;
        }
    }
    for(int i=1;i<=n;i++){
        mp[(1ll*i-1)*(n-i)+n-1]++;
    }
    for(int i=1;i<=q;i++){
        ll x;
        cin>>x;
        if(mp.count(x)){
            cout<<mp[x]<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}