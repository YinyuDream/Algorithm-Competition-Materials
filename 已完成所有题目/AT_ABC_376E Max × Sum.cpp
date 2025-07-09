#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=1e6+10;
void solve(){
    int k,n;
    cin>>n>>k;
    vector<pll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    sort(a.begin()+1,a.end());
    multiset<ll> s;
    ll sum=0;
    for(int i=1;i<=k-1;i++){
        s.insert(a[i].second);
        sum+=a[i].second;
    }
    ll ans=(sum+a[k].second)*a[k].first;
    for(int i=k+1;i<=n;i++){
        if(s.size()&&a[i-1].second<*s.rbegin()){
            sum-=*s.rbegin();
            s.erase(prev(s.end()));
            sum+=a[i-1].second;
            s.insert(a[i-1].second);
        }
        ans=min(ans,(sum+a[i].second)*a[i].first);
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
