#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll work(vector<int> &a){
    if(a.size()==1)
        return a[0];
    int n=a.size()-1;
    vector<ll> dp(n+1,1e18);
    dp[0]=0;
    auto mul=[&](int l,int r){
        ll res=1;
        for(int i=l;i<=r;i++){
            res=res*a[i];
            if(res>1e17)
                return -1ll;
        }
        return res;
    };
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            ll val=mul(j+1,i);
            if(val!=-1)
                dp[i]=min(dp[i],dp[j]+mul(j+1,i));
        }
    }
    return dp[n];
}
void solve(){
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    ll ans=1e18;
    for(int i=1;i<n;i++){
        vector<int> a;
        a.push_back(0);
        for(int j=1;j<=n;j++){
            if(j==i){
                int val=10*(s[j]-'0')+s[j+1]-'0';
                a.push_back(val);
            }else if(j==i+1){
                continue;
            }else{
                a.push_back(s[j]-'0');
            }
            
        }
        
        ans=min(ans,work(a));
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