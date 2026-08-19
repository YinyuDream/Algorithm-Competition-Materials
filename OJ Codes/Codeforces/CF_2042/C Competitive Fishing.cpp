#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
    vector<ll> sum_0(n+1),sum_1(n+1),delta(n+1);
    for(int i=1;i<=n;i++){
        sum_0[i]=sum_0[i-1]+(s[i]=='0');
        sum_1[i]=sum_1[i-1]+(s[i]=='1');
        delta[i]=sum_1[i]-sum_0[i];
    }
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i=1;i<n;i++){
        q.push(delta[i]);
    }
    ll tot=0;
    for(int i=2;i<=n;i++){
        tot+=q.top();
        q.pop();
        if((i-1)*delta[n]-tot>=k){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}