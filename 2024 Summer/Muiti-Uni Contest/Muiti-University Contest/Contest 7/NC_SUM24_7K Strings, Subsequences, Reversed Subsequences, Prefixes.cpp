#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef unsigned long long ULL;
const int N = 1e6 + 5;
ll h1[N], h2[N], p[N];
void solve() {
	ll n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	ll ans=0;
	vector<int>v(t.size()+1),w(t.size()+1);
	int pos=0;
	for(int i=0;i<n;i++){
		if(pos==m)break;
		if(s[i]==t[pos]){
			v[pos]=i;
			pos++;
		}
	}
	if(pos!=m){
		cout<<"0\n";
		return;
	}
	pos=0;
    ll base=131;
	for(int i=n-1;i>=0;i--){
		if(pos == m) break;
		if( s[i] == t[pos]){
			w[pos] = i ;
			pos++;
		}
	}
	if(pos!=m){
		cout<<"0\n";
		return;
	}
	ll l=v[m-1]+1;
	ll r=w[m-1]-1;
	vector<ll>dp(n+1);
	dp[l-1]=1;
	map<char,int>mp;
	ll mod=1e9+7;
	for(int i=l;i<=r;i++){
		if(i>=n||i<=-1)break;
		dp[i]=2*dp[i-1];
		if(mp[s[i]]!=0){
			dp[i]-=dp[mp[s[i]]-1];
		}
		dp[i]%=mod;
		mp[s[i]]=i;
	}
	if(r>=0&&r<n){
	dp[r]=(dp[r]+mod)%mod;
	ans+=dp[r];
	}
	//cout<<ans<<'\n';
    p[0] = 1;
    for (int i = 1; i <m; ++ i) {
        p[i] = p[i - 1] * base;
    }
     
    for (int i = m-1; i >= 0; -- i) {
        h1[i] = h1[i + 1] + t[i] * p[m-1- i];
        h2[i] = h2[i + 1] * base + t[i];  
    }
	for(int i=m-1;i>=1;i--){
		if(h1[i]==h2[i]){
			if(w[i-1]>v[m-1]){
				ans++;
				ans%=mod;
			}
		}
	}
    if(h1[0]==h2[0]){
        ans++;
    }
	ans%=mod;
	cout<<ans<<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while (t--) {
		solve();
	}
	return 0;
}
