#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll mod=998244353;
ll quickpow(ll a, ll b)
{
		 a %= mod;
	   ll ret = 1;
	     for(; b; b >>= 1, a = a * a % mod) 
		        if(b & 1) ret = ret * a % mod;
	     return ret;
 }
void solve(){
	ll a,b;
	cin>>a>>b;
	cout<<a*quickpow(a+b,mod-2)%mod<<' '<<b*quickpow(a+b,mod-2)%mod<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--) {
		solve();
	}
	
	return 0;
}