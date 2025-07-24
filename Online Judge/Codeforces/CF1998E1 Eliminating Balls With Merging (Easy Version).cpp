#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> can(n+1,1);
    vector<ll> a(n+1),sum(n+1);
    vector<pair<ll,int>> b(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<n;i++){
        b[i]={sum[i]-a[i+1],i};
    }
    sort(b.begin()+1,b.end());
    set<int> pos;
    pos.insert(n);
    int now=1;
    for(int l=1;l<=n;l++){
        int r=lower_bound(sum.begin()+l,sum.end(),a[l-1]+sum[l-1])-sum.begin()-1;
        if(l==1){
            r=n-1;
        }
        if(r==l-1){
            continue;
        }
        while(now<n&&b[now].first<sum[l-1]){
            pos.insert(b[now].second);
            now++;
        }
        if(pos.empty()){
            continue;
        }
        auto it=pos.upper_bound(r);
        if(it!=pos.begin()){
            it=prev(it);
            if(*it>=l){
                fill(can.begin()+l,can.begin()+(*it)+1,0);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=can[i];
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