#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long 
void solve(){
	int l,x,y;
	cin>>l>>x>>y;
	double ans=l;
	if( y * y + (x - ans) * (x- ans) <=l * l){
		cout<<"Yes\n";
		cout<<ans<<'\n';
	}
	else{
		ans=0;
        if(y * y + (x - ans) * (x- ans) <=l*l){
		cout<<"Yes\n";
		cout<<ans<<'\n';
	   }
        else{
        cout<<"No\n";
        }
	}
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
