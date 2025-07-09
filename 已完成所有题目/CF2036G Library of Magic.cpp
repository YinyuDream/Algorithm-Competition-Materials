#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll n;
    cin>>n;
    auto ask=[&](ll l,ll r){
        cout<<"xor "<<l<<" "<<r<<endl;
        cout.flush();
        ll x;
        cin>>x;
        return x;
    };
    auto output=[&](ll a,ll b,ll c){
        cout<<"ans "<<a<<" "<<b<<" "<<c<<endl;
        cout.flush();
    };
    ll tot=ask(1,n);
    if(tot==0){
        ll val=0;
        while((1ll<<(val+1))-1<=n){
            val++;
        }
        while(ask(1,(1ll<<val)-1)==0){
            val--;
        }
        ll pos=(1ll<<val)-1;
        ll l=1,r=pos;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ask(1,mid)==0){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ll a=l;
        l=pos+1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ask(mid,n)==0){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ll c=r;
        ll b=tot^a^c;
        output(a,b,c);
    }else{
        ll l=1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ask(1,mid)==0){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ll a=l;
        l=1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ask(mid,n)==0){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ll c=r;
        ll b=tot^a^c;
        output(a,b,c);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}