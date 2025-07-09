#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll x,ans=1e18;
    cin>>x;
    ll nn=sqrt(x)/2,ss=sqrt(x);
    for(ll n=max(1ll,nn-20);n<=nn+20;n++){
        for(ll s=max(1ll,ss-20);s<=ss+20;s++){
            if(s<=x&&(2*n-1)*s>=x&&x%2==s%2){
                ans=min(ans,s+2*n);
            }
            if(2*s<=x&&2*n*s>=x&&x%2==0){
                ans=min(ans,s+2*n+1);
            }
        }
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