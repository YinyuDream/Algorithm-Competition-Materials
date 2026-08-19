#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long 
void solve(){
	ll m,k,h;
	cin>>m>>k>>h;
	ll l=0;
	ll r=h;
    if(m==k){
        cout<<min(m,h)<<'\n';
        return;
    }
	while(l<r){
		ll mid=(l+r)/2;
		ll tot=mid;
		ll t=(m-k);
		if(mid>=m){
			tot+=(1+((mid-m)/t))*k;
		}
		if(tot>=h){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l<<'\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
