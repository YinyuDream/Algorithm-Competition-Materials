#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(k>=31)cout<<n+1;
		else if((1<<k)-1>=n)cout<<n+1;
		else cout<<(1<<k);
		cout<<endl;
	}
	return 0;
}