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
    int m;
    cin>>m;
    ll ans=0;
    vector<int> rem;
    for(int i=0;i<n;i++){
        ans+=a[i]/k;
        if(a[i]%k!=0){
            rem.push_back(k-a[i]%k);
        }
    }
    sort(rem.begin(),rem.end());
    int sz=rem.size();
    for(int i=0;i<sz;i++){
        if(m>=rem[i]){
            m-=rem[i];
            ans++;
        }else{
            break;
        }
    }
    cout<<ans+m/k<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}