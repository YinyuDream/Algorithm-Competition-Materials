#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=1;i<n;i+=2){
        int delta=a[i-1]-a[i];
        if(delta<=k){
            k-=delta;
            a[i]=a[i-1];
        }else{
            a[i]+=k;
            break;
        }
    }
    ll ans=0;
    a.push_back(0),n++;
    for(int i=1;i<n;i+=2){
        ans+=a[i-1]-a[i];
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