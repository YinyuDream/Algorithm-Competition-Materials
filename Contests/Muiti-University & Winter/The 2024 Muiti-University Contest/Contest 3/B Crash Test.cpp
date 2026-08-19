#include<bits/stdc++.h>
using i64 = long long;
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(b==0) return a;
	else{
		return gcd(b,a%b);
	}
}
void solve()
{
	int n;
	i64 D;
	std::cin >> n >> D;
	std::set<i64> h;
	for (int i = 0; i < n; i++) {
		i64 tmp;
		std::cin >> tmp;
		h.insert(tmp);
	}
	if (h.size() == 1) {
		i64 now = *h.begin();
		D %= now;
		std::cout << std::min(D, now - D);
	}
	else {
		ll g=0;
		for(auto x:h){
			g=gcd(g,x);
		}
		if(D%g==0){
			cout<<"0\n";
		}
		else{
			cout<<min(D%g,g-D%g);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}