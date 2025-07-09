#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m+1==n){
        cout<<0<<endl;
        return;
    }
    sort(a.begin(),a.end());
    set<int> s;
    for(int i=0;i<n;i++){
        int val=a[i];
        while(val){
            s.insert(val);
            val/=2;
        }
    }
    ll ans=1e18;
    int len=n-m,mid=len/2;
    for(auto val:s){
        vector<pair<int,int>> b(n);
        for(int i=0;i<n;i++){
            b[i].first=a[i];
            while(b[i].first/2>=val){
                b[i].first/=2;
                b[i].second++;
            }
        }
        sort(b.begin(),b.end());
        priority_queue<int> q;
        ll sum=0;
        vector<ll> pre(n),suf(n);
        for(int i=0;i<mid;i++){
            q.push(b[i].second-b[i].first);
            sum+=b[i].second-b[i].first;
        }
        for(int i=mid-1;i<n;i++){
            pre[i]=sum;
            if(i==n-1) break;
            if(b[i+1].second-b[i+1].first<q.top()){
                sum+=b[i+1].second-b[i+1].first-q.top();
                q.pop();
                q.push(b[i+1].second-b[i+1].first);
            }
        }
        while(q.size()){
            q.pop();
        }
        sum=0;
        for(int i=n-1;i>=n-mid;i--){
            q.push(b[i].second+b[i].first);
            sum+=b[i].second+b[i].first;
        }
        for(int i=n-mid;i>=0;i--){
            suf[i]=sum; 
            if(i==0) break;
            if(b[i-1].second+b[i-1].first<q.top()){
                sum+=b[i-1].second+b[i-1].first-q.top();
                q.pop();
                q.push(b[i-1].second+b[i-1].first);
            }
        }
        ll tot=1e18;
        if(len%2==1){
            for(int i=mid;i<n-mid;i++){
                tot=min(tot,pre[i-1]+suf[i+1]+b[i].second);
            }
        }else{
            for(int i=mid-1;i<n-mid;i++){
                tot=min(tot,pre[i]+suf[i+1]);
            }
        }
        ans=min(ans,tot);
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