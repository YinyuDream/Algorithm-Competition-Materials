#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<pii> a,b;
    vector<char> f;
    for(int i=0;i<n;i++){
        int x,y;
        char c;
        cin>>x>>y>>c;
        a.push_back({x,y});
        f.push_back(c);
    }
    auto perimeter=[&](int t){
        ll lx=1e18,rx=-1e18,ly=1e18,ry=-1e18;
        for(int i=0;i<n;i++){
            ll x=a[i].first,y=a[i].second;
            if(f[i]=='N') y+=t;
            if(f[i]=='S') y-=t;
            if(f[i]=='W') x-=t;
            if(f[i]=='E') x+=t;
            lx=min(lx,x);
            rx=max(rx,x);
            ly=min(ly,y);
            ry=max(ry,y);
        }
        return 2*(rx-lx+ry-ly);
    };
    ll l=0,r=1e10;
    while(l+3<=r){
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;
        if(perimeter(m1)<perimeter(m2)) r=m2;
        else if(perimeter(m1)>perimeter(m2)) l=m1;
        else l=m1,r=m2;
    }
    ll ans=1e18;
    for(ll i=l;i<=r;i++) ans=min(ans,perimeter(i));
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}