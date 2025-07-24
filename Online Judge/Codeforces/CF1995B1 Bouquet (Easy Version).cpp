#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int r=-1;
    ll ans=0,sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]<=m&&a[i]<=a[0]+1){
            sum+=a[i];
            r=max(r,i);
        }else{
            break;
        }
    }
    ans=sum;
    for(int i=1;i<n;i++){
        sum-=a[i-1];
        while(r<n-1&&sum+a[r+1]<=m&&a[r+1]<=a[i]+1){
            r++;
            sum+=a[r];
        }
        ans=max(ans,sum);
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