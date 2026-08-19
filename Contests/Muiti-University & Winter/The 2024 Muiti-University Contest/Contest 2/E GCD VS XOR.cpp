#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
	ll x;
	cin>>x;
    if(x-((x)&(-x))==0){
    cout<<-1<<'\n';
    }
    else
    cout<<x-((x)&(-x))<<'\n';
	
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t = 1;
	cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}