#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=ex_gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<ll> a(n),p(n),b(n),q(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    }
    ll l=0,r=1e15;
    auto check=[&](ll lim){
        ll tot=0;
        for(int i=0;i<n;i++){
            ll gcd=__gcd(a[i],b[i]);
            ll val=lim;
            if(val%gcd!=0){
                val=(val/gcd+1)*gcd;
            }
            auto ok=[&](ll val){//a[i]*x+b[i]*y=val
                ll x,y;
                ll d=ex_gcd(a[i],b[i],x,y);
                ll t=val/d;
                x*=t,y*=t;
                ll dx=b[i]/d,dy=a[i]/d;
                ll k1=ceil(-1.0*(x)/dx);
                ll k2=floor(1.0*(y)/dy);
                if(k1>k2)return false;
                return true;
            };
            for(int i=val;i;i+=gcd){
                if(ok(i)){
                    val=i;
                    break;
                }
            }
            tot+=min(val/a[i]*p[i],val/b[i]*q[i]);
        }
        return tot<=x;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}