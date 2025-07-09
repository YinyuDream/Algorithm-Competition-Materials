#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve(){
	string s;
	cin>>s;
	ll a,b;
	a=b=0;
	for(auto x:s){
		if(x=='Y'){
			a++;
		}
		if(x=='N'){
			b++;
		}
	}
	if(a>=4){
		cout<<1<<'\n';
	}
	else
	if(b>=2){
		cout<<-1<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
	
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