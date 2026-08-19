#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    int k;
    cin>>n>>m;
    cin>>k;
    int ans=0;
    for(int i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        ans+=x<=y;
    }
    cout<<ans<<endl;
}